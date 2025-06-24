FROM kalilinux/kali-rolling

RUN apt-get update && \
    apt-get install -y socat && \
    rm -rf /var/lib/apt/lists/*

COPY ./libc.so.6 /lib/x86_64-linux-gnu/libc.so.6
COPY ./ld-linux-x86-64.so.2 /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2

RUN useradd -m -s /bin/bash ctfuser \
    && echo 'ctfuser:ctfpassword' | chpasswd \
    && mkdir /home/ctfuser/challenge \
    && chown -R root:ctfuser /home/ctfuser/challenge \
    && chmod 555 /home/ctfuser/challenge

COPY ./chal /home/ctfuser/challenge/
COPY ./flag.txt /home/ctfuser/challenge/
RUN chmod 777 /home/ctfuser \
    && chown -R root:ctfuser /home/ctfuser/challenge \
    && chmod 777 /home/ctfuser/challenge \
    && chown root:ctfuser /home/ctfuser/.bashrc && chmod 444 /home/ctfuser/.bashrc

RUN echo "cd /home/ctfuser/challenge" >> /home/ctfuser/.bashrc

RUN chsh -s /bin/bash ctfuser
RUN chmod 700 /home/ctfuser

WORKDIR /home/ctfuser/challenge
USER ctfuser

CMD socat TCP-LISTEN:5000,reuseaddr,fork EXEC:"/home/ctfuser/challenge/chal,stderr"
