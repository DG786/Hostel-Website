alias install="sudo apt-get install";
alias update="sudo apt-get update";
alias autoremove="sudo apt-get autoremove";
alias removeapp="sudo apt-get remove";
alias purgeapp="sudo apt-get purge";

alias files="sudo nautilus /";

alias bashrc="sudo subl /etc/bash.bashrc";
alias dotbashrc="sudo subl $HOME/.bashrc";
alias aptconf="sudo subl /etc/apt/apt.conf";
alias fishconf="sudo subl ~/.config/fish/config.fish";

alias restart="sudo shutdown -r +0";
alias shutdown="sudo shutdown +0";
alias remount="sudo mount -o remount,rw";

alias gc="gcc -o a ";

cat ~/.config/fish/config.fish | awk '{if($1=="alias")printf("%s, ",$2);}';

