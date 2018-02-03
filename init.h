// Initialization packets (7 bytes each)
// First 4 bytes are equivalent to string "EGIS", which must be just a company identificator
// Other 3 bytes are not recognized yet

// Answers for each packet contains 7 bytes again
// First 4 bytes are reversed "EGIS", which is "SIGE", i guess it is company id again
// Other 3 bytes are not recognized yet
// Sending last packet makes sensor return image
static unsigned char init[][7] =
{
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x20, 0x3f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x58, 0x3f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x21, 0x09 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x57, 0x09 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x22, 0x03 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x56, 0x03 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x23, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x55, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x24, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x54, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x16, 0x3e },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x09, 0x0b },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x14, 0x03 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x15, 0x00 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x0f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x10, 0x00 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x11, 0x38 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x12, 0x00 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x13, 0x71 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x03, 0x80 },
	{ 0x45, 0x47, 0x49, 0x53, 0x00, 0x02, 0x80 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x2f },
	{ 0x45, 0x47, 0x49, 0x53, 0x06, 0x00, 0xfe }
};

// After sending initial packets device returns image data
// To ask device to send image data again, host needs to send four additional packets
// Further work is to repeatedly send four repeat packets and read image data

// Image repeat request
// First 4 bytes are the same as in initialization packets
static unsigned char repeat[][7] =
{
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x0f },
	{ 0x45, 0x47, 0x49, 0x53, 0x00, 0x02, 0x0f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x2f },
	{ 0x45, 0x47, 0x49, 0x53, 0x06, 0x00, 0xfe }
};


/*
static const unsigned char init_1[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x20, 0x3f
},



static const unsigned char init_2[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x58, 0x3f
},



static const unsigned char init_3[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x21, 0x09
},



static const unsigned char init_4[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x57, 0x09
},



static const unsigned char init_5[7] = {
0x45, 0x47, 0x49, 0x53,
0x01, 0x22, 0x03
},



static const unsigned char init_6[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x56, 0x03
},



static const unsigned char init_7[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x23, 0x01
},



static const unsigned char Init_8[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x55, 0x01
},



static const unsigned char init_9[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x24, 0x01
},



static const unsigned char pkt19[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x54, 0x01
},



static const unsigned char pkt21[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x16, 0x3e
},



static const unsigned char pkt23[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x09, 0x0b
},



static const unsigned char pkt25[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x14, 0x03
},



static const unsigned char pkt27[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x15, 0x00
},



static const unsigned char pkt29[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x02, 0x0f
},



static const unsigned char pkt31[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x10, 0x00
},



static const unsigned char pkt33[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x11, 0x38
},



static const unsigned char pkt35[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x12, 0x00
},



static const unsigned char pkt37[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x13, 0x71
},



static const unsigned char pkt39[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x03, 0x80
},



static const unsigned char pkt41[7] = {
0x45, 0x47, 0x49, 0x53, 
0x00, 0x02, 0x80
},



static const unsigned char pkt43[7] = {
0x45, 0x47, 0x49, 0x53, 
0x01, 0x02, 0x2f
},



static const unsigned char pkt45[7] = {
0x45, 0x47, 0x49, 0x53, 
0x06, 0x00, 0xfe
},


*/