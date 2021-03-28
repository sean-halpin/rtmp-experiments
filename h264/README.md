
### gstreamer dev env
```
cd dir/gst-build
meson --prefix=/gst_local/ builddir
ninja -l 3 -C builddir
meson install -C builddir

cd h264/plugin
meson builddir
```

### raw file - I420
```
GST_DEBUG=2 gst-launch-1.0 -v videotestsrc num-buffers=3 ! video/x-raw,format=I420  ! filesink location=videotestsrc.i420.raw
hexdump -C -n 256 videotestsrc.i420.raw
sha256sum ./videotestsrc.i420.raw
```
### raw file - NV12
```
GST_DEBUG=2 gst-launch-1.0 -v videotestsrc num-buffers=3 ! video/x-raw,format=NV12  ! filesink location=videotestsrc.nv12.raw
hexdump -C -n 256 videotestsrc.nv12.raw
sha256sum ./videotestsrc.nv12.raw
```
### h264 file
```
GST_DEBUG=2 gst-launch-1.0 -v videotestsrc num-buffers=3 ! nvh264enc ! filesink location=videotestsrc.264
ffplay ./videotestsrc.264
```
### mp4 file
```
GST_DEBUG=2 gst-launch-1.0 -v videotestsrc num-buffers=3 ! nvh264enc ! h264parse ! mp4mux ! filesink location=videotestsrc.264.mp4
ffplay ./videotestsrc.264.mp4
```
