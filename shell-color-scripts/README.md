# Shell Color Scripts

![Screenshot of shell-color-scripts](https://gitlab.com/dwt1/dotfiles/raw/master/.screenshots/dotfiles12.png)

A collection of terminal color scripts I've accumulated over the years.
Included 52 beautiful terminal color scripts.

# Installing shell-color-scripts on Arch Linux

All you need to do is download the PKGBUILD from this repository.  Then run the following command:

	makepkg -cf

This will create a file that ends in .pkg.tar.xz (for example, shell-color-scripts-0.1-1-x86_64.pkg.tar.xz).  Then run:

	sudo pacman -U *.pkg.tar.zst

Alternately, you could also install shell-color-scripts from the AUR using an AUR helper such as yay:

	yay -S shell-color-scripts

# Installing shell-color-scripts on NixOS or nixpkgs (unstable only) 

Shell-color-scripts is packaged for nixpkgs (unstable only). Although manpages and shell completions are not packaged *yet*

##### For NixOS users (unstable only)

    nix-env -iA nixos.dt-shell-color-scripts
##### For nixpkgs users (unstable only)
    
    nix-env -iA nixpkgs.dt-shell-color-scripts

# Installing shell-color-scripts on Fedora

Shell-color-scripts is packaged for the two supported versions of Fedora at the moment of reading and also for Rawhide as a Copr package for all the supported architectures and includes the manpages and shell completions. Installation instructions can be found on the [Copr page of the package](https://copr.fedorainfracloud.org/coprs/foopsss/shell-color-scripts/).


# Installing shell-color-scripts on other Linux distributions

Download the source code from this repository or use a git clone:

	git clone https://gitlab.com/dwt1/shell-color-scripts.git
	cd shell-color-scripts
    sudo make install

    # Removal
    sudo make uninstall

    # optional for zsh completion
    sudo cp completions/_colorscript /usr/share/zsh/site-functions

    # optional for fish shell completion
    sudo cp completions/colorscript.fish /usr/share/fish/vendor_completions.d

# Usage

    colorscript --help
    Description: A collection of terminal color scripts.

    Usage: colorscript [OPTION] [SCRIPT NAME/INDEX]
    -h, --help, help        	Print this help.
    -l, --list, list        	List all installed color scripts.
    -r, --random, random    	Run a random color script.
    -e, --exec, exec        	Run a specified color script by SCRIPT NAME or INDEX.
    -a, --all, all          	List the outputs of all colorscripts with their SCRIPT NAME
    -b, --blacklist, blacklist	Blacklist a color script by SCRIPT NAME or INDEX.

# The Scripts Are Located in /opt/shell-color-scripts/colorscripts

The source for shell-color-scripts is placed in:

	/opt/shell-color-scripts/colorscripts

For even more fun, add the following line to your .bashrc or .zshrc and you will run a random color script each time you open a terminal:

	### RANDOM COLOR SCRIPT ###
	colorscript random
