(* Calculate mean *)
let calculate_mean lst =
  let sum = List.fold_left (fun acc x -> acc + x) 0 lst in
  let count = List.length lst in
  float_of_int sum /. float_of_int count

(* Calculate median *)
let calculate_median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted (len / 2 - 1) in
    let mid2 = List.nth sorted (len / 2) in
    float_of_int (mid1 + mid2) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

(* Calculate mode *)
let calculate_mode lst =
  (* Count frequencies *)
  let rec count_freq lst acc =
    match lst with
    | [] -> acc
    | x :: rest ->
        let current_count = 
          try List.assoc x acc 
          with Not_found -> 0 
        in
        let new_acc = (x, current_count + 1) :: List.remove_assoc x acc in
        count_freq rest new_acc
  in
  
  let freq_list = count_freq lst [] in
  
  (* Find max frequency *)
  let max_freq = List.fold_left 
    (fun max (_, count) -> if count > max then count else max) 
    0 freq_list 
  in
  
  (* Get all modes *)
  let modes = List.filter 
    (fun (_, count) -> count = max_freq) 
    freq_list 
  in
  let mode_values = List.map (fun (value, _) -> value) modes in
  (List.sort compare mode_values, max_freq)

(* Print list *)
let print_list lst =
  print_string "[";
  let rec print_elements = function
    | [] -> ()
    | [x] -> print_int x
    | x :: rest -> 
        print_int x; 
        print_string ", "; 
        print_elements rest
  in
  print_elements lst;
  print_string "]"

(* Print modes *)
let print_modes (modes, freq) =
  print_string "Mode(s): [";
  let rec print_mode_list = function
    | [] -> ()
    | [x] -> print_int x
    | x :: rest -> 
        print_int x; 
        print_string ", "; 
        print_mode_list rest
  in
  print_mode_list modes;
  Printf.printf "] (appears %d time(s))\n" freq

(* Main program *)
let () =

  (* Test case 1 *)
  let data = [15; 23; 15; 42; 18; 23; 15; 30; 25; 18] in
  print_string "Input Data: ";
  print_list data;
  print_newline ();
  print_newline ();
  
  let mean = calculate_mean data in
  Printf.printf "Mean: %.2f\n" mean;
  
  let median = calculate_median data in
  Printf.printf "Median: %.2f\n" median;
  
  let mode_result = calculate_mode data in
  print_modes mode_result;
 
