#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7735S _panel_instance;
  lgfx::Bus_SPI _bus_instance;

 public:
  LGFX(int csPin) {
    {
      auto cfg = _bus_instance.config();
      cfg.spi_host = VSPI_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = 20000000;
      cfg.freq_read = 14000000;
      cfg.spi_3wire = true;
      cfg.use_lock = true;  // Set true to use transaction locking
      cfg.dma_channel = SPI_DMA_CH_AUTO;
      cfg.pin_sclk = 18;
      cfg.pin_mosi = 23;
      cfg.pin_miso = -1;
      cfg.pin_dc = 2;  // SPI D/C or RS

      _bus_instance.config(cfg);  // Reflects the setting value on the bus
      _panel_instance.setBus(&_bus_instance);  // Place the bus on the panel
    }

    {  // Configure display panel control settings.
      auto cfg = _panel_instance.config();

      cfg.pin_cs = csPin;
      cfg.pin_rst = 4;
      cfg.pin_busy = -1;

      // The following setting values are general default values set for each
      // panel, so please comment out any items you are unsure of and try again.

      cfg.panel_width = 80;     // Actual displayable width
      cfg.panel_height = 160;   // Actual display height
      cfg.offset_x = 26;        // Panel X direction offset amount
      cfg.offset_y = 1;         // Panel Y direction offset amount
      cfg.offset_rotation = 2;  //  0~7 (4~7 are upside down)
      cfg.dummy_read_pixel =
          8;  // Number of dummy read bits before pixel readout
      cfg.dummy_read_bits = 1;  // Number of bits for dummy read before reading
                                // data other than pixels
      cfg.readable = false;     // Set to true if data reading is possible
      cfg.invert = true;  // パネルの明暗が反転してしまう場合 trueに設定
      cfg.rgb_order = false;  // Set to true if the red and blue colors of the
                              // panel are swapped.
      cfg.dlen_16bit =
          false;  // Set to true for panels that transmit data length in 16-bit
                  // units using 16-bit parallel or SPI.
      cfg.bus_shared = false;  // Set to true when sharing the bus with the SD
                               // card (control the bus using drawJpgFile, etc.)

      // Set the following only if the display is misaligned with a variable
      // pixel number driver such as ST7735 or ILI9163.
      cfg.memory_width = 132;
      cfg.memory_height = 162;

      _panel_instance.config(cfg);
    }

    setPanel(&_panel_instance);  // Set the panel to be used.
  }
};