</head>
<body>

  <h1>CS50 4th Module</h1>
    <p>This repository contains the solutions for the labs and problem sets of Module 4 from Harvard's CS50 course. The module focuses on memory management in C, including pointers, file I/O, and manipulating data at the byte level to handle common file formats like WAV audio and BMP images.</p>

  <hr>
  <h3>Important Note for Execution</h3>
    <p>
        The code in this repository represents the solutions to the exercises and labs. It is not a standalone project. To compile and run these programs, you need the specific CS50 development environment and libraries provided by the course.
    </p>
    <p>
        For the complete context and to set up the necessary environment, please refer to the official CS50 course offered in Brazil by Fundação Estudar:
        <a href="https://www.estudarfora.org.br/cc50-v2/">https://www.estudarfora.org.br/cc50-v2/</a>
    </p>
    <hr>

  <h2>Project 1: Volume</h2>
    <h3>Description</h3>
    <p>
        <code>volume</code> is a C program that modifies the volume of a WAV audio file. It takes an input file, an output file, and a floating-point factor as command-line arguments. The program scales the volume of the audio by multiplying each sample by the given factor.
    </p>
    <h3>Implementation Details</h3>
    <ol>
        <li>The program first opens the input WAV file for binary reading and the output WAV file for binary writing.</li>
        <li>It reads the 44-byte header from the input file and writes it, unmodified, to the output file.</li>
        <li>It then enters a loop, reading the audio data one sample at a time (each sample being a 16-bit signed integer, or <code>int16_t</code>).</li>
        <li>For each sample, it multiplies the value by the user-provided factor. The result is rounded to the nearest integer to maintain audio data integrity.</li>
        <li>The new, modified sample is written to the output file.</li>
        <li>This process continues until all samples from the input file have been processed.</li>
    </ol>

  <h2>Project 2: Filter </h2>
    <h3>Description</h3>
    <p>
        <code>filter</code> is a program that applies various image filters to 24-bit BMP (Bitmap) files. The user can specify a filter via a command-line flag, along with an input image and an output file name. The program reads the BMP, applies the chosen filter to its pixels, and saves the result as a new BMP file.
    </p>
    <h3>Implemented Filters</h3>
    <ul>
        <li>
            <strong>Grayscale:</strong> Converts the image to black and white. This is achieved by calculating the average of the red, green, and blue values for each pixel and setting all three color channels to this new average value.
        </li>
        <li>
            <strong>Reflect:</strong> Flips the image horizontally. For each row of pixels, the program swaps the pixels on the left side with their corresponding pixels on the right side.
        </li>
        <li>
            <strong>Blur (Box Blur):</strong> Softens the image. The new color value for each pixel is calculated as the average of the colors of itself and all of its 8 immediate neighbors (a 3x3 grid). This required creating a temporary copy of the image to ensure calculations were based on the original pixel values.
        </li>
        <li>
            <strong>Edges (Sobel Operator):</strong> Detects and highlights edges in the image. This advanced filter uses two 3x3 kernels (Gx and Gy) to calculate the color gradient in the horizontal and vertical directions for each pixel. The final color value is determined by combining these gradients using the formula <code>sqrt(Gx^2 + Gy^2)</code> and capping the result at 255.
        </li>
    </ul>

  <h2>Problem 3: Recover</h2>
    <h3>Description</h3>
    <p>
        <code>recover</code> is a C program that functions as a digital forensics tool. It recovers JPEG images from a raw memory card image file (<code>card.raw</code>). The program scans the file for the unique byte pattern that signifies the start of a JPEG file.
    </p>
    <h3>Implementation Details</h3>
    <ol>
        <li>The program opens the memory card image file provided as a command-line argument.</li>
        <li>It reads the file in 512-byte blocks, which corresponds to the block size of a FAT file system.</li>
        <li>For each block, it checks the first four bytes to see if they match the JPEG signature (<code>0xff 0xd8 0xff</code>, followed by a byte from <code>0xe0</code> to <code>0xef</code>).</li>
        <li>When a new JPEG signature is found, the program closes any previously open JPEG file and opens a new one for writing, with a sequential filename (e.g., <code>000.jpg</code>, <code>001.jpg</code>, etc.).</li>
        <li>If a JPEG file is currently open, the program continues to write the 512-byte blocks to it.</li>
        <li>This continues until the end of the memory card image is reached, at which point the final files are closed. The program successfully recovers 50 JPEGs from the provided image.</li>
    </ol>

</body>
</html>
