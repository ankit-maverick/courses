// ######## Specifications
bw_array = [50 100 100];
f0_array = [185 196 220 220 247 247 220 196 185 185 196 220 220 247 247 220 196 185 185 196 220 220 247 277 294 294 330 294 277 247 277 247 220];
time = [200 200 400 400 400 400 600 200 400 200 200 400 400 400 400 600 200 400 200 200 400 400 400 400 800 300 300 700 600 300 300 300 600];
formants = [730, 1090, 2440]; 
fs = 16000;

// ######## Initialization
h = 1;
song = [];
song_duration = 0;

// ######## Code for Speech synthesis made during the 1st Computing Assignment
for q = 1:length(time)
	for i = 1:3
   		r = exp(-%pi*bw_array(i)/fs);
    	theta = 2*%pi*formants(i)/fs;

    	w = 0: 0.005 :%pi;
   		// sfpp = single formant pole pair
    	sfpp = 1 - 2*r*cos(theta)*exp(-%i*w) + r^2*exp(-2*%i*w);
    	h = h./sfpp;
	end

	n = 0:1:155;
	r = exp(-%pi*bw_array(i)/fs)
	theta1 = 2*%pi*formants(1)/fs;
	theta2 = 2*%pi*formants(2)/fs;
	theta3 = 2*%pi*formants(3)/fs;
	hn1 = (r^n.*sin((n+1)*theta1)/sin(theta1));
	hn2 = (r^n.*sin((n+1)*theta2)/sin(theta2));
	hn3 = (r^n.*sin((n+1)*theta3)/sin(theta3));
	hn_temp = convol(hn1, hn2);
	hn = convol(hn_temp, hn3);
	nn = 0:1:465;

	f0 = f0_array(q);
	zr = floor(fs/f0);
	// Dirty quick hack :(
	xn=[ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr) ones(1,1) zeros(1,zr)];
	xn = [xn xn];

	song_duration = song_duration + time(i);
	k=0:1:(464 + 75*(1+zr));
	yn=convol(xn,hn);
	yn = yn(length(hn):length(yn) - length(hn));
	scf(q);
	plot(yn);
	num_samples = time(i)*16;
	song = [song yn(1:num_samples)];
end

wavwrite(song, fs, 16, 'vowel_song');
soundsec(song_duration/1000,[16000]);
