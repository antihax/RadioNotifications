Get-ChildItem  "p:/RadioNotifications/Source/tempdocs/*.xml" -Recurse  | ForEach-Object {
  $content = Get-Content $_.FullName
  $content = $content -replace "private", "public"
  $content = $content -replace 'inline="yes"', 'inline="no"'
  Set-Content $_.FullName $content
}