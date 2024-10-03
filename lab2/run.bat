@echo off
for /L %%c in (1,1,4) do (
    for /L %%t in (1,1,16) do (
        "./lab2.exe" wolf.bmp wolf-out.bmp %%c %%t
  echo ===============
    )
)
pause