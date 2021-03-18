#include <gst/gst.h>

int main(int argc, char *argv[])
{
    const gchar *RTMP_URL = g_getenv("RTMP_URL");
    const gchar *RTMP_AUTH_KEY = g_getenv("RTMP_AUTH_KEY");
    gchar pipelineString[1024];
    g_snprintf(pipelineString, 1024,
               "videotestsrc is-live=1 ! video/x-raw,width=1280,height=720,framerate=30/1 ! timeoverlay ! x264enc bitrate=2000 ! video/x-h264,profile=main ! queue ! mux. audiotestsrc is-live=1 wave=12 ! avenc_aac ! queue ! mux. flvmux streamable=1 name=mux ! rtmpsink location=\"%s/x/%s app=live2\"", RTMP_URL, RTMP_AUTH_KEY);
    g_print("%s", pipelineString);

    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    gst_init(&argc, &argv);

    pipeline =
        gst_parse_launch(pipelineString,
                         NULL);

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    bus = gst_element_get_bus(pipeline);
    msg =
        gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                   GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    if (msg != NULL)
        gst_message_unref(msg);
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}