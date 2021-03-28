#ifndef __GST_HALPINX264_H__
#define __GST_HALPINX264_H__

#include <gst/gst.h>

G_BEGIN_DECLS

#define GST_TYPE_HALPINX264 (gst_halpin_x264_get_type())
G_DECLARE_FINAL_TYPE (GstHalpinX264, gst_halpin_x264,
    GST, PLUGIN_TEMPLATE, GstElement)

struct _GstHalpinX264
{
  GstElement element;

  GstPad *sinkpad, *srcpad;

  gboolean silent;
};

G_END_DECLS

#endif /* __GST_HALPINX264_H__ */
