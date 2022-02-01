<div id="top"></div>

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/CSI-Rockets-Eletronics/GroundStationUI">
    <img src="https://avatars.githubusercontent.com/u/91352917?s=400&u=3c77960d62926a34507d7c9d3185588a27539205&v=4" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Ground Station User Interface</h3>

  <p align="center">
    A simple, lightweight user interface to monitor the launch operations of our rocket.
    <br />
    <br />
    <br />
    <a href="https://github.com/CSI-Rockets-Eletronics/GroundStationUI/issues">Report Bug</a>
      | 
    <a href="https://github.com/CSI-Rockets-Eletronics/GroundStationUI/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->

## About The Project

<div align="center">
<figure>
    <img src="https://i.imgur.com/wNu3vcQ.png" alt="Current Stage Screenshot" width="600">
    <br>
    <figcaption>Screenshot of the current state</figcaption>
    <br>
</figure>
<figure>
    <img src="https://i.imgur.com/luzaoYA.png" alt="Design Mockup" width="600">
    <br>
    <figcaption>Mockup of the desired final state</figcaption>
    <br>
</figure>
</div>

This is an user interface for monitoring the launch of our Rocket. The design philosophy is to be simple, lightweight, platform agnostic, efficient, and expandable. Currently it operates with a mouse and keyboard but we have plans to move it to full on touch controls.

<p align="right">(<a href="#top">back to top</a>)</p>

### Built With

- [C++](https://www.cplusplus.com/)
- [SDL](https://www.libsdl.org/)
- [CMake](https://cmake.org/)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Getting Started

To start your must install GCC (the compiler) and SDL2 (The library) in your system. This will vary a lot from OS to OS. If you are using Windows, simplying putting the SDL2 folder on the root of this repo will make it work (might work with other OS as well but we never tested).

Additionally you can install cmake to build using it.

It is recommended that you work on this project using the IDE Clion with cmake because it makes debugging and building much simpler.
Contact Victor at vcb2115@columbia.edu on how to do this and to get pre-made project config files.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.

- gcc -
  https://gcc.gnu.org/install/
- SDL2 -
  https://wiki.libsdl.org/Installation
- SDL True Type Font -
  https://github.com/libsdl-org/SDL_ttf
- Optional but recommended: CLion IDE (Free for students) and CMake to make this run as a CLion project. Requires some aditional files. Contact Victor at vcb2115@columbia.edu. -
  https://www.jetbrains.com/clion/

### Installation

Clone the repo:

```sh
git clone https://github.com/CSI-Rockets-Eletronics/GroundStationUI.git
```

or, if you use ssh:

```sh
git clone git@github.com:CSI-Rockets-Eletronics/GroundStationUI.git
```

### Building

1. On Windows:
   ```sh
   .\compile.bat
   ```
2. On Unix
   ```sh
   ./compile.sh
   ```

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->

## Usage

1. Connect the ground station to the computer's USB and initiate the driver, which will spill the data into a file in the disk.
2. Use the command:
   ```sh
   ./main path/to/GroundStationOutputDataFile.txt
   ```
3. Profit

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ROADMAP -->

## Roadmap

- [ ] Implement all of the Firing Station data display
- [ ] Implement the basic rocket data display
- [ ] Add functional launch,abort, etc. buttons.
- [ ] Implement a real time map with the rocket's location and trajectory

See the [open issues](https://github.com/CSI-Rockets-Eletronics/GroundStationUI/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTRIBUTING -->

## Contributing

Github allows everyone to work on this proejct together in parallel and remotely, so you are encouraged to download this project onto your computer and work on it while comitting often. After you have a sucessful update, you should create a pull request to merge it into the master branch. Any contributions you make are **greatly appreciated**.

Here's how to do it:

1. Download the Project to your pc
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request (Go on the main page of the repo, click "Pull requests", and then "New pull request")

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

Victor Barros - [@twitter_handle](https://twitter.com/twitter_handle) - vcb2115@columbia.edu

Project Link: [https://github.com/CSI-Rockets-Eletronics/GroundStationUI](https://github.com/CSI-Rockets-Eletronics/GroundStationUI)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->

## Acknowledgments

- [Readme Template Source](https://github.com/othneildrew/Best-README-Template)
- [Tutorial on how to use SDL2](https://lazyfoo.net/tutorials/SDL/)
<p align="right">(<a href="#top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/CSI-Rockets-Eletronics/GroundStationUI.svg?style=for-the-badge
[contributors-url]: https://github.com/CSI-Rockets-Eletronics/GroundStationUI/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/CSI-Rockets-Eletronics/GroundStationUI.svg?style=for-the-badge
[forks-url]: https://github.com/CSI-Rockets-Eletronics/GroundStationUI/network/members
[stars-shield]: https://img.shields.io/github/stars/CSI-Rockets-Eletronics/GroundStationUI.svg?style=for-the-badge
[stars-url]: https://github.com/CSI-Rockets-Eletronics/GroundStationUI/stargazers
[issues-shield]: https://img.shields.io/github/issues/CSI-Rockets-Eletronics/GroundStationUI.svg?style=for-the-badge
[issues-url]: https://github.com/CSI-Rockets-Eletronics/GroundStationUI/issues
[license-shield]: https://img.shields.io/github/license/CSI-Rockets-Eletronics/GroundStationUI.svg?style=for-the-badge
[license-url]: https://github.com/CSI-Rockets-Eletronics/GroundStationUI/blob/master/LICENSE.txt
