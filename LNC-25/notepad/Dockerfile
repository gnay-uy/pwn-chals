FROM pwn.red/jail
COPY --from=debian:bookworm / /srv
COPY ./chal /srv/app/run
COPY ./flag.txt /srv/app/flag.txt
RUN chmod +x /srv/app/run
