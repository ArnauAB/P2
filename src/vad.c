#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "pav_analysis.h"
#include "vad.h"

const float FRAME_TIME = 10.0F; /* in ms. */

/* 
 * As the output state is only ST_VOICE, ST_SILENCE, or ST_UNDEF,
 * only this labels are needed. You need to add all labels, in case
 * you want to print the internal state in string format
 */

const char *state_str[] = {
  "UNDEF", "S", "V", "INIT"
};

const char *state2str(VAD_STATE st) {
  return state_str[st];
}

/* Define a datatype with interesting features */
typedef struct {
  float zcr;
  float p;
  float am;
} Features;

/* 
 * TODO: Delete and use your own features!
 */

Features compute_features(const float *x, int N) {
  /*
   * Input: x[i] : i=0 .... N-1 
   * Ouput: computed features
   */
  /* 
   * DELETE and include a call to your own functions
   *
   * For the moment, compute random value between 0 and 1 
   */
  Features feat;
  feat.p = compute_power(x,N);
  feat.zcr = compute_zcr(x,N,16000);
  feat.am = compute_am(x,N);
  return feat;
}

/* 
 * TODO: Init the values of vad_data
 */

VAD_DATA * vad_open(float rate, float t_min) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;

  vad_data->num_MS = 0; 
  vad_data->num_MV = 0; 
  vad_data->num_min = t_min;
  return vad_data;
}

VAD_STATE vad_close(VAD_DATA *vad_data) {
if (vad_data->state == ST_MAYBE_SILENCE){
  vad_data->state = ST_SILENCE;
}
if (vad_data->state == ST_MAYBE_VOICE){
  vad_data->state = ST_VOICE;
}
  VAD_STATE state = vad_data->state;

  free(vad_data);
  return state;
}

unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}

/* 
 * TODO: Implement the Voice Activity Detection 
 * using a Finite State Automata
 */

VAD_STATE vad(VAD_DATA *vad_data, float *x, float alpha1, float alpha2) {

  /* 
   * TODO: You can change this, using your own features,
   * program finite state automaton, define conditions, etc.
   */

  Features f = compute_features(x, vad_data->frame_length);
  vad_data->last_feature = f.p; /* save feature, in case you want to show */

  switch (vad_data->state) {
  case ST_INIT:
    vad_data->state = ST_SILENCE;
    vad_data->p_sup = f.p + alpha1;
    vad_data->p_inf = f.p + alpha2;
    break;

  case ST_SILENCE:
    if (f.p > vad_data->p_sup) {
      if (vad_data->num_min==0){
        vad_data->state = ST_VOICE;
      } else {
        vad_data->state = ST_MAYBE_VOICE;
      }
      
    }
    break;

  case ST_VOICE:
    if (f.p < vad_data->p_inf){
      if (vad_data->num_min==0){
        vad_data->state = ST_SILENCE;
      } else {
        vad_data->state = ST_MAYBE_SILENCE;
      }
    }
    break;

  case ST_MAYBE_SILENCE:
    if (f.p < vad_data->p_sup) {
      if (vad_data->num_MS>=vad_data->num_min){
      vad_data->num_MS = 0;
      vad_data->state = ST_SILENCE;
      } else {
        vad_data->num_MS++;
      }
    } else {
      vad_data->state = ST_VOICE;
    }
    break;

  case ST_MAYBE_VOICE:
    if (f.p > vad_data->p_inf){
      if (vad_data->num_MV>=vad_data->num_min){
      vad_data->num_MV = 0;
      vad_data->state = ST_VOICE;
      } else {
        vad_data->num_MV++;
      }
    } else {
      vad_data->state = ST_SILENCE;
    }
    break;

  case ST_UNDEF:
    break;
  }

  if (vad_data->state == ST_SILENCE){
    return ST_SILENCE;
  }
  else if (vad_data->state == ST_VOICE)
  {
    return ST_VOICE;
  }
  else
    return ST_UNDEF;
}

void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  fprintf(out, "%d\t%f\n", vad_data->state, vad_data->last_feature);
}
