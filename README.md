So this here's the arduino code for a handbuilt MIDI foot controller, intended
for use with Sooperlooper.

I have made no attempt to conform with any MIDI standards as regards what
signals I actually use, as Sooperlooper will let me bind any action to any MIDI
signal, and I don't intend to manufacture this device for actual retail sale
(I'm not even sure if it makes a difference). I'm mostly just using notes, so
that I can spend my time coding and playing music instead of poring over the
MIDI spec to find the most appropriate signal to send for what I wanna do.

Right now I have 3 buttons, about to add one more for tap-tempo, wired to a 1/4
jack so I can just use a generic guitar footswitch. I want to end up with a
device with 12-15 buttons, three buttons for four loops, a switch to change the
ranges of loops I'm working on, and some global controls. I'll probably have to
refactor the code a bit when I add the extra buttons, particularly in how I
have the switch changing things. Haven't thought that far ahead.

As of right now, though, it works! I've had a couple lovely jam sessions with
it.
