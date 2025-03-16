param(
    [Parameter(Mandatory=$true)]
    [string]$InputFile,
    [Parameter(Mandatory=$true)]
    [string]$ExpectedFile,
    [Parameter(Mandatory=$true)]
    [string]$ActualFile,
    [int]$Timeout = 1,
    [Parameter(Mandatory=$true)]
    [string]$Command
)

# Build full command arguments: assuming the solution reads from standard input.
$arguments = "$InputFile $ExpectedFile $ActualFile"

# Start the process using cmd.exe /c to run the specified command.
$proc = Start-Process -FilePath "cmd.exe" -ArgumentList "/c", $Command, $arguments -PassThru -NoNewWindow

$timeoutMs = $Timeout * 1000
$elapsed = 0
$interval = 100

while (-not $proc.HasExited -and $elapsed -lt $timeoutMs) {
    Start-Sleep -Milliseconds $interval
    $elapsed += $interval
}

if (-not $proc.HasExited) {
    Stop-Process -Id $proc.Id -Force
    Write-Host "$InputFile TLE"
} else {
    Write-Host "$InputFile Completed"
}
