#include <stdio.h>
#include "spotify_api.h" //   Spotify API daal

int main() {
  struct tm  6:30; // set desired alarm time

  int wake_up = 0;
  while (!wake_up) {
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);

    if (current_tm->tm_hour == alarm_time.tm_hour && current_tm->tm_min == alarm_time.tm_min) {
      play_spotify_playlist("Wake Up Playlist"); // call playlist function from Spotify API 🖐️
      wake_up = 1;
    }

    sleep(60); // check every minute
  }

  return 0;
}