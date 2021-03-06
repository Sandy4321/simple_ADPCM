#ifndef WAVE_HEADER_H
#define WAVE_HEADER_H

#include <stdint.h>

#define PCM_FORMAT 1
#define ADPCM_FORMAT 2

typedef struct{ /* cabecalho padrao de um arquivo WAVE */

	int32_t ChunkID; /* cabecalho RIFF (Resource Interchange File Format) */
	int32_t ChunkSize; /* tamanho do arquivo menos 8 */
	int32_t Format; /* contem as letras "WAVE" (0x57415645 no formato big-endian) */
	int32_t Subchunk1ID; /* contem as letras "fmt " (0x666d7420 no format big-endian) */
	int32_t Subchunk1Size; /* 16 for PCM */
	uint16_t AudioFormat; /* PCM = 1 (significa uma quantizacao linear)  ADPCM = 2 */
	uint16_t NumChannels; /* canais: 1 = mono e 2 = stereo */
	int32_t SampleRate; /* frequencia de amostragem */
	int32_t ByteRate; /* SampleRate * NumChannels * BitPerSample/8 */
	uint16_t BlockAlign; /* NumChannels * BitsPersSample/8 */
	uint16_t BitsPerSample; /* numero de bits por amostra: 8 ou 16 bits */
	int32_t Subchunk2ID; /* contem as letras "data" (0x64617461 no formato big-endian) */
	int32_t Subchunk2Size; /* numero de bytes para os dados */

}HeaderType;

#endif
