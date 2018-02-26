# 1 "src/stage4.c" 1
# 1 "C:/c68/include/stdio.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 11 "C:/c68/include/stdio.h" 2
# 20 "C:/c68/include/stdio.h"
typedef unsigned long  size_t;
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 1 "src/stage4.c" 2
# 1 "src/include/render.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 4 "src/include/render.h" 2
# 1 "src/include/model.h" 1
# 1 "src/include/const.h" 1
# 1 "src/include/types.h" 1
# 10 "src/include/types.h"
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;

typedef char *string;

typedef int bool;



typedef enum {
    left, right, down, stop
} direction_t;
typedef enum {
    alien_bomb, spaceship_laser
} shot_t;

typedef struct {
    uint16 x;
    uint16 y;
    uint16 width;
    uint16 height;
} hitbox_t;
# 4 "src/include/const.h" 2
# 53 "src/include/const.h"
const uint32 MAX_SCORE = 9999;
# 4 "src/include/model.h" 2
# 1 "src/include/types.h" 1
# 5 "src/include/model.h" 2
# 12 "src/include/model.h"
typedef struct Shot {
    int x;
    int y;
    shot_t type;
    bool is_active;
    bool is_out_of_bounds;
} Shot;

typedef struct Spaceship {
    int x;
    int y;
    direction_t direction;
    hitbox_t hitbox;
    Shot shots[1 ];
    int shot_count;
    bool is_alive;
} Spaceship;

typedef struct Alien {
    int row;
    int col;
    int x;
    int y;
    int score_val;
    bool is_alive;
    uint16* bitmap[16 ];
} Alien;

typedef struct Armada {
    Alien aliens[5 ][8 ];
    int top_left_x;
    int top_left_y;
    int bottom_right_x;
    int bottom_right_y;
    direction_t move_direction;
    Shot shots[3 ];
    int shot_count;
} Armada;

typedef struct Scorebox {
    int x;
    int y;
    int score;
} Scorebox;

typedef struct Model {
    bool is_playing;
    bool is_game_over;
    Spaceship player;
    Armada armada;
    Scorebox scorebox;

} Model;


void move_spaceship(Spaceship *spaceship, direction_t direction);

void spaceship_shoot(Spaceship *spaceship);

void init_spaceship(Spaceship *spaceship);

void set_spaceship_x(Spaceship *spaceship, uint16 x);



void alien_collide(Alien *alien);


void move_armada(Model *model);
void alien_shoot(Armada *armada);
void init_armada(Armada *armada);


void move_shot(Shot *shot);

void shot_hit_alien(Shot *player_shot, Alien *alien);

void shot_hit_player(Shot *player_shot, Spaceship *alien);
void init_shots(Shot shots[], shot_t type, int max_shots);

bool laser_collides_with_alien(Alien *alien, Shot *laser);

bool bomb_collides_with_spaceship(Spaceship *alien, Shot *laser);


void set_score(Scorebox *scorebox, uint32 score);

uint32 get_score(Scorebox *scorebox);

void _update_score_text(Scorebox *scorebox);


void init_model(Model *model);

void game_over(Model *model);

void pause_game(Model *model);

void resume_game(Model *model);

void _log_model(const char *model_name, const char *message, ...);
# 6 "src/include/render.h" 2
# 1 "src/include/types.h" 1
# 7 "src/include/render.h" 2
# 1 "src/include/const.h" 1
# 8 "src/include/render.h" 2
# 1 "src/include/event.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 4 "src/include/event.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 5 "src/include/event.h" 2
# 1 "src/include/model.h" 1
# 6 "src/include/event.h" 2
# 1 "src/include/types.h" 1
# 7 "src/include/event.h" 2
# 1 "src/include/const.h" 1
# 8 "src/include/event.h" 2
# 16 "src/include/event.h"
void on_spaceship_move(Spaceship *spaceship, unsigned long key);

void on_armada_move(Model *model);
void on_laser_move(Shot *laser);
void on_bomb_move(Shot *bomb);

void on_shoot();

void alien_shoots();

void on_alien_hit_bottom(Alien *alien);

void on_laser_hit_boundary(Shot *laser);
void on_bomb_hit_boundary(Shot *bomb);
void on_laser_hit_alien(Shot *laser, Alien *hit);

void on_bomb_hit_player(Spaceship *spaceship, Shot *bomb);


void on_game_start(Model *model);

void on_game_pause(Model *model);

void on_game_over(Model *model);
# 9 "src/include/render.h" 2
# 1 "src/include/bitmap.h" 1
# 1 "src/include/types.h" 1
# 4 "src/include/bitmap.h" 2





extern const uint16 bitmap[];
# 10 "src/include/render.h" 2
# 1 "src/include/raster.h" 1
# 1 "src/include/types.h" 1
# 4 "src/include/raster.h" 2
# 18 "src/include/raster.h"
void plot_pixel(uint8 *base, int x, int y);
# 25 "src/include/raster.h"
void plot_vertical_line(uint8 *base, int x, int y, int height);
# 32 "src/include/raster.h"
void plot_horizontal_line(uint8 *base, int x, int y, int width);

void plot_horizontal_line__inverse(uint8 *base, int x, int y, int width);
# 42 "src/include/raster.h"
void plot_line(uint8 *base, int x1, int y1, int x2, int y2);
# 51 "src/include/raster.h"
void plot_rectangle(uint8 *base, int x, int y, int width, int height);

void plot_rectangle__inverse(uint8 *base, int x, int y, int width, int height);
# 60 "src/include/raster.h"
void plot_bitmap_8(uint8 *base, int x, int y, uint8 *bitmap, int height);
# 67 "src/include/raster.h"
void plot_bitmap_16(uint16 *base, int x, int y, uint16 *bitmap, int height);




void print_char(uint8 *base, int x, int y, char ch);




void print_string(uint8 *base, int x, int y, char *str);
# 84 "src/include/raster.h"
void print_num(uint8 *base, int x, int y, uint16 num);




void clear_screen(uint32 *base);
# 11 "src/include/render.h" 2
# 1 "src/include/font.h" 1
# 1 "src/include/types.h" 1
# 4 "src/include/font.h" 2


extern const uint8 font[];
# 12 "src/include/render.h" 2
# 1 "src/include/sprites.h" 1
# 1 "src/include/types.h" 1
# 4 "src/include/sprites.h" 2
# 1 "src/include/const.h" 1
# 5 "src/include/sprites.h" 2


extern uint16 alien1_bitmap[16 ];
extern uint16 alien2_bitmap[16 ];
extern uint16 alien3_bitmap[16 ];
extern uint16 spaceship_bitmap[16 ];
# 13 "src/include/render.h" 2


void render_spaceship(const Spaceship *spaceship, uint16 *base);

void render_armada(const Armada *armada, uint16 *base);

void render_alien(const Alien *alien, uint16 *base);

void render_shot(const Shot *shot, uint16 *base);

void render_scoreboard(const Scorebox *scorebox, uint16 *base);

void render(Model *model, uint16 *base);
# 2 "src/stage4.c" 2


int main() {
  Model model;
  uint16 *base = (uint16*) (void*)_trap_14_w((short)0x2) ;
  uint32 *screen = (uint32) (void*)_trap_14_w((short)0x2) ;
  on_game_start(&model);
  clear_screen__inverse(base);
  render(&model, base);
  return 0;
}
