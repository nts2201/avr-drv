# Introduction #

This page describe the USART API found in "usart.h".


# Multiple USART vs Single USART device #

While some devices support multiple USART(ATmega128 as an example), some devices only have a single USART port(ATmega8). We still want something that can fit on both. The proposed solution here is a preprocessor one.

Code has two cores:
  * usartMulti
  * usartSingle

Each core shares equivalent functions with distinctive sufix. All functions of the multi core have to be called with a port number whereas all functions of the single core does not have to specify the port, obviosly.

Now the API requires all function to be called with the port number. When compiled for a single USART port device, the port number is discarded by the preprocessor, thus saving process time and code size.

# Functions Name #

  * usartSetBaudRate(port, baudRate)
  * usartSetNumBit(port, numBit)
  * usartSetParity(port, partity)
  * usartSetStopBit(port, stopBit)
  * usartSetMode(port, mode)
  * usartEnableRx(port, enable)
  * usartEnableTx(port, enable)
  * usartPutc(port, data)
  * usartPuts(port, data)
  * usartGetc(port, data)
  * usartIsTx(port)
  * usartEnableRxInt(port, enable)
  * usartEnableTxBufInt(port, enable)
  * usartEnableTxCmpInt(port, enable)
  * usartPutcISR(port, data)
  * usartGetcISR(port, data)