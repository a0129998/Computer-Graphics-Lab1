A0129998B

what am i drawing:
a really cute brown cat's head on a light yellow background with colourful flowerly spots behind it. 

primitives and transformaitons i have used:

primitives: 
	1. GL_POLYGON
	2. GL_LINE_STRIP
	3. GL_LINES
	
transformaitons:
	1. glScalef()
	2. glTranslatef()
	
methods that i have modified:
	1. display()
	2. main()
	
methods i have created:
	void circle(float radius, int startDeg, int endDeg, GLenum mode);
	void shiftCircle(float xTrans, float yTrans, float radius, int startDeg, int endDeg, GLenum mode);
	void drawEllipse(float radiusX, float radiusY, int startDeg, int endDeg);
	void shiftEllipse(float radiusX, float radiusY, int startDeg, int endDeg, float xPos, float yPos);
	void mouseClickEvent(int button, int state, int x, int y);

	void drawCatface();
	void drawRightEar();
	void drawCatEye(float radius, float xPos, float yPos);
	void drawCatMouth(float radius, float x, float y, float mouthLen, float mouthBre);
	void drawCatWiskers();
	void drawHighLights();
	void drawFlower(float x, float y, float radius, float rHori, float rVert, float r, float g, float b, int petalN);
	void allDisplay();
	void drawBackgroundFlowers();
	
things the TA should know:
	1. wrote cool functions to draw circles and ellipses and shift them to locations i want
	2. prototype of functions are declared at the top of the code for TA to reference
	3. the cool extra feature is that the click listener will detect the location of the click and print the coordinates in the console.
	4. the location of the click is always scaled to the window which both the x and y coordinate ranges from -10 to 10.
	5. I have seprated the drawing of each parts for the sake of the TA
	6. I mixed bright colors with a gradient for the ears and fur highlights
	7. you can zoom out to have a better look at the pattern in the background.
	
coolest thing(s) in my drawing:
	1. i really like the cat because it's so cute and i really like cats.
	2. the gradient of the fur highlights and the inner and outer ears
	3. the cool hack of locating the coordinate in scale with the window when clicking on the window allowed me to easily find the positions i want the points of my polygon to me at. It saved me a lot of time as i can just click the screen to find out where i should put my points.