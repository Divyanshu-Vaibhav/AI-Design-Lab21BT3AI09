# AI-Design-Lab21BT3AI09 

Welcome to the 8th semester Design Lab code implementations repository! This project focuses on weather forecasting using advanced AI techniques.

## About This Project

This repository contains implementations for weather forecasting models and data analysis tools developed as part of the 8th semester Design Lab course. The project leverages modern deep learning approaches to generate accurate weather predictions and visualize meteorological data.

## Setup Instructions ⚙️

### Forecast Generation

To generate forecasts, follow these steps:

1. Register at [ECMWF](https://www.ecmwf.int/) and [CDS](https://cds.climate.copernicus.eu/) websites
2. Obtain API keys from both platforms
3. Place the API keys in the FourCastNetV2 Jupyter notebook as demonstrated in the code comments

### Temperature Data Parsing

For parsing real temperature grid data:

1. Download the 31×31 resolution file from the [IMD Pune](https://www.imdpune.gov.in/) website for your desired year
2. Our analysis uses 2023 data as a reference point
3. Follow the data parsing instructions in the relevant notebooks

### Visualization Setup

To visualize model performance:

1. Generate forecasts using the FourCastNetV2 notebook
2. Organize the forecast outputs in the folder structure specified in the metData notebook
3. Run the visualization scripts to evaluate model accuracy

## Repository Structure 📁

- `FourCastv2.ipynb`: Main notebook for generating weather forecasts
- `metData.ipynb`: Notebook for meteorological data processing and visualization
- `DataFetch.c`: C program to parse data from grid temperature file obtained from IMD pune website

## Features ✨

- **AI-Powered Forecasting**: Leverage state-of-the-art deep learning models for weather prediction
- **Data Visualization**: Comprehensive tools to visualize and analyze meteorological data
- **Real-World Data Integration**: Parse and process actual temperature grid files from IMD
- **Performance Analysis**: Tools to evaluate and compare model performance metrics

## Technologies Used 🛠️

- Python
- PyTorch
- Jupyter Notebooks
- Matplotlib for visualization
- NumPy/Pandas for data manipulation

## Getting Started 🚀

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/AI-Design-Lab21BT3AI09.git
   cd AI-Design-Lab21BT3AI09
   ```

2. Install required dependencies:
   ```bash
   pip install -r requirements.txt
   ```

3. Follow the setup instructions above to configure your API keys and data sources

4. Run the Jupyter notebooks to generate forecasts and visualize results

## Contributing 🤝

Contributions are welcome! Please feel free to submit a Pull Request.

## License 📄

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments 🙏

- Thanks to ECMWF and CDS for providing access to weather data
- IMD Pune for temperature grid files
- All contributors who have helped improve this project

Happy Forecasting! ☀️🌧️❄️
