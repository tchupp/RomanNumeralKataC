FROM ubuntu:14.04
MAINTAINER tchupp

# Install Basic Packages
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y git
RUN apt-get install -y git-core
RUN apt-get install -y wget
RUN apt-get install -y build-essential
RUN apt-get install -y pkg-config
RUN apt-get install -y check
RUN apt-get install -y zsh

# Install Zsh
RUN git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh \
      && cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc \
      && chsh -s /bin/zsh

# Make dev-home
RUN mkdir /home/dev

CMD ["zsh"]
