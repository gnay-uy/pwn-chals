FROM pwn.red/jail
COPY --from=kalilinux/kali-rolling@sha256:434fc2be9018218f8039cdb6d67989b3bd8e22e48aa373f1680934ddfec1ee30 / /srv
COPY ./chal /srv/app/run
COPY ./flag.txt /srv/app/flag.txt
RUN chmod +x /srv/app/run
