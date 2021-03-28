### Export Env Variables
```
export RTMP_URL=rtmp://x.rtmp.youtube.com/live2
export RTMP_AUTH_KEY=xxxx-zzzz-3333-9999
```

### Build and Run
```
➜  rtmp-experiments gcc rtmp_app.c -o rtmp_app `pkg-config --cflags --libs gstreamer-1.0`
➜  rtmp-experiments GST_DEBUG=1 ./rtmp_app  
```

### Links

 - [RTMP Spec](https://wwwimages2.adobe.com/content/dam/acom/en/devnet/rtmp/pdf/rtmp_specification_1.0.pdf)
 - [H264 BASELINE ENCODER IMPL - Thesis](http://research.sabanciuniv.edu/8308/1/guneymehmet.pdf)
 - [PSNR - Peak Signal to Noise Ratio, an objective quality
measure](https://en.wikipedia.org/wiki/Peak_signal-to-noise_ratio)
 - [AVC - Advanced Video Coding](https://en.wikipedia.org/wiki/Advanced_Video_Coding)
 - [CAVLC - Context Adaptive Variable Length Coding](https://en.wikipedia.org/wiki/Context-adaptive_variable-length_coding)
 - [Video Compression Picture Types](https://en.wikipedia.org/wiki/Video_compression_picture_types)
 - [Luma](https://en.wikipedia.org/wiki/Luma_(video))
 - [Chroma](https://en.wikipedia.org/wiki/Chrominance)
 - [Macroblocks & Motion Vectors, ffmpeg view](https://trac.ffmpeg.org/wiki/Debug/MacroblocksAndMotionVectors)
    - [Macroblock](https://en.wikipedia.org/wiki/Macroblock)
    - [Motion Vector](https://en.wikipedia.org/wiki/Motion_vector)
 - [Smallest H264 Encoder](https://www.cardinalpeak.com/worlds-smallest-h-264-encoder)
   - [hello264.c](https://cardinalpeak.com/downloads/hello264.c)
 - [Chroma Subsampling](https://en.wikipedia.org/wiki/Chroma_subsampling)
 - [H264 Reference Software](http://iphome.hhi.de/suehring/tml/JM%20Reference%20Software%20Manual%20(JVT-AE010).pdf)
 - [H264 Spec](https://www.itu.int/rec/T-REC-H.264)
 - [h264bitstream tool (SPS & PPS)](https://github.com/aizvorski/h264bitstream)
 - [Pdf - H264 Standard](https://last.hit.bme.hu/download/vidtech/k%c3%b6nyvek/Iain%20E.%20Richardson%20-%20H264%20(2nd%20edition).pdf)
 - [YCrCb](https://en.wikipedia.org/wiki/YCbCr)
 - [Hadamard transform](https://en.wikipedia.org/wiki/Hadamard_transform)
  

```
# Motion Vector display in video
ffplay -flags2 +export_mvs -i rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov -vf codecview=mv=pf+bf+bb
```

### Making a H264 Baseline Stream

 - [x264enc](https://gstreamer.freedesktop.org/documentation/x264/index.html?gi-language=c)

```
gst-launch-1.0 -v videotestsrc num-buffers=1000 ! x264enc pass=5 quantizer=25 speed-preset=6 ! video/x-h264, profile=baseline ! mp4mux ! filesink location=videotestsrc.mp4

ffprobe -hide_banner -print_format json -i videotestsrc.mp4 -show_streams
ffprobe -hide_banner -print_format json -i videotestsrc.mp4 -show_frames

```

```
gst-launch-1.0 -v videotestsrc num-buffers=1000 ! x264enc pass=5 quantizer=25 speed-preset=6 ! video/x-h264, profile=baseline ! filesink location=videotestsrc.mp264

x264 videotestsrc.264 --input-res=320x240 -o playable_video.mp4
```

