<?php

// Inialize session
session_start(profile);

// Delete certain session
unset($r['Roll_Number']);
// Delete all session variables
// session_destroy();

// Jump to login page
header('Location: LogIndex.php');

?>