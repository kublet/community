# Community 

[![Docs](https://img.shields.io/badge/docs-developers.thekublet-blue?style=flat-square)](https://developers.thekublet.com)

Community is a platform for users of Kublet to publish their apps for the Kublet community to download and use for their kublet device.

![softlight_trim](https://github.com/kublet/community/assets/4488777/83a3d8a6-d340-4569-9ca0-3136d5fb2bb0)

## Requirements

- WiFi
- Krate CLI
- Visual Studio Code
- PlatformIO (PIO)
- Kublet

Follow this [guide](https://developers.thekublet.com/docs/installation/installation/) to install.

## Getting Started

1. Fork this repository
2. Clone the fork to your local machine
3. Checkout a new branch locally
4. Make, commit and push your changes
5. Submit PR

See more guidelines on the review process [here](https://developers.thekublet.com/docs/publishing/how-to/).

### Fork and clone

```bash
git clone git@github.com:kublet/community.git
```

https://github.com/kublet/community/assets/4488777/a1517d8b-8df9-49ff-8912-af6ffe818f43

### Build

Note: You need PIO CLI in order to build krates on the command line. You can either download it via VS Code and install the PIO extension, or [install](https://docs.platformio.org/en/latest/core/installation/methods/index.html) it separately.  

We recommended using VS Code/PIO IDE for development, but the in demo videos below we will demonstrate how to develop krates entirely in the terminal for a quick overview of our process.

**Initialize a new project**

```bash
cd community/krates
git checkout -b <proj-name>
krate init <proj-name>
cd proj-name
```

https://github.com/kublet/community/assets/4488777/44354c7e-a5a1-4c7c-940c-2647c8bf59c6

**Develop**

In your krate project folder, use our krate CLI to build and flash your code. 

```bash
krate deps install
krate build
krate send <ip-addr> 
```

https://github.com/kublet/community/assets/4488777/d1da896e-d63d-404a-9101-1d5e1c4d301a

### Publish 

```bash
krate publish
```

https://github.com/kublet/community/assets/4488777/373dde9a-9450-4ff4-8df1-39072f609742

### Submit PR

Go to the local root directory of the cloned community repo. 

```bash
cd ../..
git add .
git commit -m "Add boredd krate"
git push origin <branch-name>
```

### What to include in PR

See [docs](https://developers.thekublet.com/docs/publishing/how-to/#what-to-include).
