FROM pwn.red/jail
COPY --from=debian:bookworm / /srv
COPY ./chal /srv/app/run
COPY ./flag.txt /srv/app/flag.txt
COPY ./libc.so.6 /srv/lib/x86_64-linux-gnu/libc.so.6
COPY ./ld-linux-x86-64.so.2 /srv/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
RUN chmod +x /srv/app/run
