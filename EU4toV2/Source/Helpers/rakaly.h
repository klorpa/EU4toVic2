/**
 * Melts binary encoded ironman data into normal plaintext data that can be understood by EU4
 * natively.
 *
 * Parameters:
 *
 *  - data: Pointer to immutable data that represents the ironman data. The data can be a ironman
 *  savefile in a zip format, in which case rakaly will take care of unzipping, melting, and
 *  concatenating the data into a single plaintext output. The pointer can point to ironman data
 *  that has already been unzipped.
 *  - data_len: Length of the data indicated by the data pointer. It is undefined behavior if the
 *  given length does not match the actual length of the data
 *  - out: Mutable pointer to data which will be filled with the plaintext savefile. Will not end
 *  in a null terminator. The encoding of the plaintext is not strictly defined, rakaly will dump
 *  whatever data is found as strings in the binary data such that they are bit for bit
 *  compatible. While this could mean that string data could be have a different encoding from the
 *  rest of the file, in practice only windows-1252 encoding has been seen for EU4 ironman saves.
 *  - out_len: Number of elements now contained in the out pointer.
 *
 * This function will return non-zero to indicate an error. A non-zero status code can occur from
 * the following:
 *
 *  - An early EOF
 *  - Invalid format encountered
 *  - An unresolved key (which means that rakaly needs to be updated to the latest patch)
 *  - Too many open delimiters
 *  - Too many close delimiters
 *
 * A future improvement should allow a client to expose the exact error message or expose the
 * option to ignore unknown keys instead of returning an error.
 */
char rakaly_eu4_melt(const char *data_ptr, size_t data_len, char **out, size_t *out_len);
