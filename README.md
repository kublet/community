# Community 

[![Docs](https://img.shields.io/badge/docs-developers.thekublet-blue?style=flat-square)](https://developers.thekublet.com)

Community is a platform for users of Kublet to publish their apps for the Kublet community to download and use for their [kublet device](https://thekublet.com).

![softlight_trim](https://github.com/kublet/community/assets/4488777/83a3d8a6-d340-4569-9ca0-3136d5fb2bb0)

## Requirements

- Krate CLI
- Visual Studio Code with PIO extension
- Kublet

**MacOS**

```bash
brew tap kublet/tools
brew install krate 
```

This README is meant to provide an overview of the process of contributing to community. See our developers [guide](https://developers.thekublet.com/docs/installation/installation/) for full installation steps.

## Getting Started

1. Fork this repository
2. Clone the fork to your local machine
3. Checkout a new branch locally
4. Make, commit and push your changes
5. Submit PR

[Detailed guide](https://developers.thekublet.com/docs/publishing/how-to/).

### Fork, clone, and create

After forking this repository, clone the fork and create a new project.

```bash
git clone git@github.com:<your-gh-username>/community.git
cd community/krates
git checkout -b <proj-name>
krate init <proj-name>
```

https://github.com/kublet/community/assets/4488777/4a016891-8ffc-4b83-af7e-d5ee9a7e9ff7

**Develop**

Open your project in VS Code and start developing.

https://github.com/kublet/community/assets/4488777/713d9131-ccca-4250-9778-4c1920fcd5a7

### Publish 

Before submitting your PR, run the following:

```bash
krate publish
```

https://github.com/kublet/community/assets/4488777/a5625629-8b75-4135-9970-3aa5e26cdbee

### Submit PR

Go to the local root directory of the cloned fork. 

```bash
cd /path/to/community/
git add .
git commit -m "Add boredd krate"
git push origin <branch-name>
```

### What to include in PR

See [docs](https://developers.thekublet.com/docs/publishing/how-to/#what-to-include).
