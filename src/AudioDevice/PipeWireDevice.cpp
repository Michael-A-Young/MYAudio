/**
@file
	PipeWireDevice.cpp
@brief
	Linux audio playback using PipeWire.
*/

// MYAudio
#include "AudioDevice/PipeWireDevice.h"

// PipeWire
#include <spa/param/audio/format-utils.h>

namespace MY
{

#define M_PI_M2 ( M_PI + M_PI )
#define DEFAULT_VOLUME          0.7
#define DEFAULT_RATE            44100
#define DEFAULT_CHANNELS        2

static void on_process(void* userdata)
{
	using Data = PipeWireDevice::PipeWireData;

	Data* data = reinterpret_cast<Data*>(userdata);
	pw_buffer* b = pw_stream_dequeue_buffer(data->stream);
	spa_buffer *buf;
	uint32_t i;
	int c;
	uint32_t n_frames;
	int stride;
	int16_t* dst;
	int16_t val;

	if (b == nullptr)
	{
		MY_LOG("Out of buffers");
		return;
	}

	buf = b->buffer;
	dst = static_cast<int16_t*>(buf->datas[0].data);
	if (dst == nullptr)
	{
	    return;
	}

	stride = sizeof(int16_t) * DEFAULT_CHANNELS;
	n_frames = buf->datas[0].maxsize / stride;
	if (static_cast<bool>(b->requested))
	{
		n_frames = SPA_MIN(b->requested, n_frames);
	}

	constexpr uint32_t MN_440 = 440;
	constexpr float MN_32767 = 32767.0F;

    for (i = 0; i < n_frames; i++) {
        data->accumulator += M_PI_M2 * MN_440 / DEFAULT_RATE;
        if (data->accumulator >= M_PI_M2)
		{
            data->accumulator -= M_PI_M2;
		}

        /* sin() gives a value between -1.0 and 1.0, we first apply
         * the volume and then scale with 32767.0 to get a 16 bits value
         * between [-32767 32767].
         * Another common method to convert a double to
         * 16 bits is to multiple by 32768.0 and then clamp to
         * [-32768 32767] to get the full 16 bits range. */
        val = static_cast<int16_t>(sin(data->accumulator) * DEFAULT_VOLUME * MN_32767);
		for (c = 0; c < DEFAULT_CHANNELS; c++)
		{
           *dst++ = val;
		}
    }

    buf->datas[0].chunk->offset = 0;
    buf->datas[0].chunk->stride = stride;
    buf->datas[0].chunk->size = n_frames * stride;

    pw_stream_queue_buffer(data->stream, b);
};

PipeWireDevice::PipeWireDevice()
	: AudioDevice()
	, mData({
		.loop = nullptr,
		.stream = nullptr,
		.accumulator =0L })
	, mStreamEvents({
		.version = PW_VERSION_STREAM_EVENTS,
		.process = on_process})
{
}

void PipeWireDevice::Initialise()
{
	pw_init(nullptr, nullptr);

	MY_LOG("Initialised PipeWire\n"
			"Compiled PipeWire {}\n"
			"Linked PipeWire {}",
			pw_get_headers_version(),
			pw_get_library_version());

	mData.loop = pw_main_loop_new(nullptr);

	mData.stream = pw_stream_new_simple(
			pw_main_loop_get_loop(mData.loop),
			"MyAudio",
			pw_properties_new(
				PW_KEY_MEDIA_TYPE, "Audio",
				PW_KEY_MEDIA_CATEGORY, "Playback",
				PW_KEY_MEDIA_ROLE, "Game",
				NULL
			),
			&mStreamEvents,
			&mData);

	const struct spa_pod* params[1];
	uint8_t buffer[kBufferSize];
    struct spa_pod_builder b = SPA_POD_BUILDER_INIT(buffer, sizeof(buffer));

	struct spa_audio_info_raw rawInfo =
		SPA_AUDIO_INFO_RAW_INIT(
            .format = SPA_AUDIO_FORMAT_S16,
            .rate = kDefaultRate,
            .channels = kDefaultChannels
		);

	params[0] = spa_format_audio_raw_build(&b,
			SPA_PARAM_EnumFormat,
			&rawInfo
		);

	pw_stream_flags streamFlags =
		static_cast<pw_stream_flags>(
			PW_STREAM_FLAG_AUTOCONNECT |
			PW_STREAM_FLAG_MAP_BUFFERS |
			PW_STREAM_FLAG_RT_PROCESS
		);

	pw_stream_connect(mData.stream,
		PW_DIRECTION_OUTPUT,
        PW_ID_ANY,
		streamFlags,
		params, 1);

	pw_main_loop_run(mData.loop);
}

void PipeWireDevice::Shutdown()
{
	pw_stream_destroy(mData.stream);
	pw_main_loop_destroy(mData.loop);

	mData.stream = nullptr;
	mData.loop = nullptr;

	pw_deinit();
}

DeviceVoice* PipeWireDevice::CreateVoice()
{
	return nullptr;
}

bool PipeWireDevice::SubmitBuffer()
{
	return false;
}

bool PipeWireDevice::Start()
{
	return false;
}

bool PipeWireDevice::Stop()
{
	return false;
}

bool PipeWireDevice::Pause()
{
	return false;
}

void PipeWireDevice::SetVolume(float /*volume*/)
{
}

void PipeWireDevice::SetPitch(float /*pitch*/)
{
}

} // namespace MY
