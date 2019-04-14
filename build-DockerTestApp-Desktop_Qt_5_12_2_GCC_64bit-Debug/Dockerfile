#FROM ubuntu:18.04
FROM alpine
ADD ./DockerTestApp /bin/myApp

COPY ./libQt5Core.so.5.12.2 /usr/lib/
RUN ln -s /usr/lib/libQt5Core.so.5.12.2 /usr/lib/libQt5Core.so.5
COPY ./libicui18n.so.56 /usr/lib/
COPY ./libicuuc.so.56 /usr/lib/
COPY ./libicudata.so.56 /usr/lib/
COPY ./libgthread-2.0.so.0 /usr/lib/
COPY ./libglib-2.0.so.0 /usr/lib/

#CMD ["/bin/myApp"]
