FROM debian:12

COPY ./chal_patched /srv/app/run
COPY ./libc.so.6 /srv/app/libc.so.6
COPY ./ld-2.35.so /srv/app/ld-2.35.so
COPY ./entry.sh /srv/app/entry.sh
COPY ./flag.txt /srv/app/flag.txt
RUN chmod 555 /srv/app/run
RUN chmod 444 /srv/app/flag.txt
RUN chmod 555 /srv/app/entry.sh
RUN chmod 555 /srv/app/libc.so.6
RUN chmod 555 /srv/app/ld-2.35.so
RUN apt-get update && apt-get install -y socat

RUN addgroup --gid 1001 nonroot && \
    adduser --uid 1001 --gid 1001 --disabled-password --gecos "" nonroot && \
    echo 'nonroot ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers
USER 1001

WORKDIR /srv/app

EXPOSE 8080

CMD [ "/srv/app/entry.sh" ]
