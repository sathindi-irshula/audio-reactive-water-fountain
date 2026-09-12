# TOUCHDESIGNER MANUAL HARDWARE TEST SCRIPT
SERIAL_OP = op('/project1/serial1')

def send_step(cmd, desc):
    if SERIAL_OP:
        print(f"TEST: {desc} -> Sending '{cmd}'")
        SERIAL_OP.send(cmd + '\n', terminator='')

if SERIAL_OP is None:
    print("ERROR: Serial DAT not found at /project1/serial1")
else:
    print("STARTING TOUCHDESIGNER MANUAL TEST...")
    run("send_step('LOW_1', 'Opening Valve 1')", delayFrames=1)
    run("send_step('LOW_0', 'Closing Valve 1')", delayFrames=60)

    run("send_step('LOWMID_1', 'Opening Valve 2')", delayFrames=120)
    run("send_step('LOWMID_0', 'Closing Valve 2')", delayFrames=180)

    run("send_step('HIGHMID_1', 'Opening Valve 3')", delayFrames=240)
    run("send_step('HIGHMID_0', 'Closing Valve 3')", delayFrames=300)

    run("send_step('HIGH_1', 'Opening Valve 4')", delayFrames=360)
    run("send_step('HIGH_0', 'Closing Valve 4')", delayFrames=420)

    run("send_step('ALL_ON', 'Opening ALL Valves')", delayFrames=480)
    run("send_step('ALL_OFF', 'Closing ALL Valves')", delayFrames=540)
