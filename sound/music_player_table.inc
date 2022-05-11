	.equiv TRACK_SIZE, 0x50
	.equiv NUM_TRACKS_BGM, 10
	.equiv NUM_TRACKS_SE1, 3
	.equiv NUM_TRACKS_SE2, 9
	.equiv NUM_TRACKS_SE3, 1

    .bss

	.section .rodata

	.align 2
gMPlayTable::
	music_player gMPlayInfo_BGM, gMPlayTrack_BGM, 16, 0
	music_player gMPlayInfo_SE1, gMPlayTrack_SE1,  3, 1
	music_player gMPlayInfo_SE2, gMPlayTrack_SE2, 11, 1
	music_player gMPlayInfo_SE3, gMPlayTrack_SE3,  1, 0
