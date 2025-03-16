param(
    [Parameter(Mandatory=$true)]
    [string]$InputFile,
    [Parameter(Mandatory=$true)]
    [string]$ExpectedFile,
    [Parameter(Mandatory=$true)]
    [string]$ActualFile,
    [int]$Timeout = 10
)

$exePath = ".\solution.exe"
$arguments = "$InputFile $ExpectedFile $ActualFile"

# Start the process
$proc = Start-Process -FilePath $exePath -ArgumentList $arguments -PassThru -NoNewWindow

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
