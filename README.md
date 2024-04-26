# Community 

[![Docs](https://img.shields.io/badge/docs-developers.thekublet-blue?style=flat-square)](https://developers.thekublet.com)

Community is a platform for users of Kublet to publish their apps for the Kublet community to download and use for their [kublet device](https://thekublet.com).

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

**Initialize a new project**

```bash
cd community/krates
git checkout -b <proj-name>
krate init <proj-name>
cd proj-name
```

https://github.com/kublet/community/assets/4488777/44354c7e-a5a1-4c7c-940c-2647c8bf59c6

**Develop**

Open your project in VS Code.

In the terminal, use our krate CLI to build and flash your code. 

```bash
krate build
krate send <ip-addr> 
```
https://github.com/kublet/community/assets/4488777/bd0986a6-5f56-4687-b87a-07da803d042f

### Publish 

```bash
krate publish
```

https://github.com/kublet/community/assets/4488777/373dde9a-9450-4ff4-8df1-39072f609742

### Submit PR

Go to the local root directory of the cloned community repo. 

```bash
cd /path/to/community/
git add .
git commit -m "Add boredd krate"
git push origin <branch-name>
```

### What to include in PR

See [docs](https://developers.thekublet.com/docs/publishing/how-to/#what-to-include).
