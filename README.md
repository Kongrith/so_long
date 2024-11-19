cc main.c libmlx42.a -Iinclude -lglfw  -ldl -pthread
./a.out

export DISPLAY=$(ip route list default | awk '{print $3}'):0
export LIBGL_ALWAYS_INDIRECT=0



libmlx_Linux.a
libmlx.a



Install minilibX
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev


https://gist.github.com/mferoc/7b76f9477e0f76befc7161800d9723f7


https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps

# push an existing repository from the command line
git remote add origin https://github.com/Kongrith/so_long.git
git branch -M main
git push -u origin main
