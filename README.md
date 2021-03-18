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