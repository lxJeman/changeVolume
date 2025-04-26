# changeVolume

**changeVolume** is a cross-platform tool for easily manipulating your system audio volume from the command line.  
It provides a simple interface to set your system's audio level, supporting multiple operating systems.

---

## Features

- **Multi-system support:** Works on Linux (and can be extended for other OSes)
- **Easy to use:** Set your volume with a single command
- **Open source:** Simple, readable code

---

## Usage

1. **Compile the code:**
   ```bash
   g++ linux.cpp -o linux
   ```

2. **Run the program:**
   ```bash
   ./linux
   ```

3. **Follow the prompts to set your system volume (0-100).**

---

## Project Structure

- `linux.cpp` — Linux implementation for changing system volume

---

## Imported Notice!

The project is currently maintained/developed on Linux/Windows specific system version, MacOS isn't fully supported, if you have a MacOS device it would be a big contribution to our community if you could, run the code to see if it works :)

---

## Contributing

Pull requests and suggestions are welcome!  
Feel free to open an issue if you want to add support for another operating system.

---

## License

This project is open source and available under the [MIT License](LICENSE).
