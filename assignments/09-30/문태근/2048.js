var fs = require('fs');

var N;
var max_block = 0;

function in_range(x, from, to) {
    if (from > to) {
        var tmp = to;
        to = from;
        from = tmp;
    }
    return from <= x && x <= to;
}

function make_moved_field(original_field, direction) {
  const delta = {
    UP: [1, 1],
    DOWN: [-1, 1],
    LEFT: [1, 1],
    RIGHT: [1, -1]
  }
  const start_end = {
    UP: [[0, N-1], [0, N-1]],
    DOWN: [[N-1, 0], [0, N-1]],
    LEFT: [[0, N-1], [0, N-1]],
    RIGHT: [[0, N-1], [N-1, 0]]
  }

  const [dx, dy] = delta[direction];
  const [[sx, ex], [sy, ey]] = start_end[direction];

  var field = Array.from(Array(N), (v, i) => original_field[i].slice());

  if (direction === 'LEFT' || direction === 'RIGHT') {
    for (var i = sx; in_range(i, sx, ex); i += dx) {
      var dst = sy;
      var merged_before = false;
      for (var j = sy; in_range(j, sy, ey); j += dy) {
        if (field[i][j] > 0) {
          if (!merged_before && 0 <= (dst-dy) && (dst-dy) < N && field[i][j] == field[i][dst-dy]) {
            field[i][dst-dy] *= 2;
            merged_before = true;
          } else {
            field[i][dst] = field[i][j];
            dst += dy;
            merged_before = false;
          }
        }
      }
      for (var j = dst; in_range(j, sy, ey); j += dy) {
        field[i][j] = 0;
      }
    }
  } else {
    for (var j = sy; in_range(j, sy, ey); j += dy) {   
      var dst = sx;
      var merged_before = false; 
      for (var i = sx; in_range(i, sx, ex); i += dx) {
        if (field[i][j] > 0) {
          if (!merged_before && 0 <= (dst-dx) && (dst-dx) < N && field[i][j] == field[dst-dx][j]) {
            field[dst-dx][j] *= 2;
            merged_before = true;
          } else {
            field[dst][j] = field[i][j];
            dst += dx;
            merged_before = false;
          }
        }
      }
      for (var i = dst; in_range(i, sx, ex); i += dx) {
        field[i][j] = 0;
      }
    }
  }
  get_max_block(field)
  return field;
}

function get_max_block(field) {
  var max = 0;
  for (var i = 0; i < N; i++) {
    for (var j = 0; j < N; j++) {
      if (field[i][j] > max) max = field[i][j];
    }
  }
  if (max_block < max) max_block = max;
}

function dfs(field, depth) {
  if (depth == 5) return;
  dfs(make_moved_field(field, 'UP'), depth+1);
  dfs(make_moved_field(field, 'DOWN'), depth+1);
  dfs(make_moved_field(field, 'LEFT'), depth+1);
  dfs(make_moved_field(field, 'RIGHT'), depth+1);
}

(function() {
  var field = [];
  var input = fs.readFileSync('/dev/stdin').toString().split('\n');
  input.pop();
  N = parseInt(input[0]);
  
  for (var i = 1; i <= N; i++) {
    field.push(input[i].split(' ').map(v => parseInt(v)));
  }
  
  dfs(field, 0);
  console.log(max_block);
})();
