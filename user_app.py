def main():
  driver_handle = open('/proc/learn_driver')
  message_from_kernel_space = driver_handle.readine()
  print(message_from_kernel_space)
  driver_handle.close()
  return

main()
