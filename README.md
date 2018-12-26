# myGit
My personal git.
bootstrap init (vademecum)...  https://sourceforge.net/projects/codeblocks/  ....



You should extract downloaded archive with

cd ~/Downloads
wget https://kent.dl.sourceforge.net/project/codeblocks/Binaries/17.12/Linux/Debian%20stable/codeblocks_17.12-1_amd64_stable.tar.xz




tar -xf codeblocks_17.12-1_amd64_stable.tar.xz

Then install extracted deb-packages:

sudo dpkg -i *17.12*.deb

And finally install missed dependencies:

sudo apt-get install -f

Please note that codeblocks-contrib will be removed on 16.04 LTS and on 18.04 LTS because of missed libhunspell-1.4-0 dependency.

Do not forget to install compiler such as GCC.

