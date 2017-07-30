alias install="sudo apt-get install";
alias update="sudo apt-get update";
alias autoremove="sudo apt-get autoremove";
alias removeapp="sudo apt-get remove";
alias purgeapp="sudo apt-get purge";

alias files="sudo nautilus /";

alias bashrc="sudo subl /etc/bash.bashrc";
alias dotbashrc="sudo subl /home/udayraj/.bashrc";
alias aptconf="sudo subl /etc/apt/apt.conf";
alias fishconf="sudo subl ~/.config/fish/config.fish";

alias restart="sudo shutdown -r +0";
alias shutdown="sudo shutdown +0";
alias remount="sudo mount -o remount,rw";


alias runjpm="cd /home/udayraj/Desktop/JSdos/MyAddon; jpm run -b /usr/bin/firefox";
alias runjpmd="cd /home/udayraj/Desktop/JSdos/MyAddon; jpm run -b /usr/bin/firefox --debug";
alias run2jpm="cd /home/udayraj/Desktop/JSdos/MyAddon; jpm run -b /usr/bin/firefox --no-copy --profile /home/udayraj/Desktop/jpm/node_modules/firefox-profile/test";

alias gc="gcc -o a ";

cat ~/.config/fish/config.fish | awk '{if($1=="alias")printf("%s, ",$2);}';

export PS1="[\[\e[32;40m\]\@\[\e[m\]\[\e[37m\]]\[\e[m\]\[\e[33;40m\] \W\[\e[m\]\[\e[35m\]>\[\e[m\]";
