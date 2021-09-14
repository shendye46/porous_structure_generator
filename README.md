# Porous Structure Generator
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->
## Table of Contents
<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
    </li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
The aim of this project is to create simulated porous media structures:
Here's how:
* Regular arrangement of atoms 
* Pore diameters obtained from a gaussian distribution
* Pores are randomlz distributed in the structure
* Structure needs to be visualized in ovito

<!-- GETTING STARTED -->
## Getting Started
To run the python script:
* create virtual environment 
* install requirements 
  ```
    pip install -r requirements.txt
  ```
* To run the existing data plotter:
  * install npm packages 
    ```
    npm install 
    ```
  * copy coordinate file to static files in plotter
  * run node application 
    ```
    node plotter/app.js
    ```
  * surf to http://localhost:3000/
    

