#include <mavlink.h>
#include <mavlink_helpers.h>
#define MAPPrintf printf
#include <testsuite.h>

#define BUFFER_LENGTH 2041

int main(int argc, char* argv[])
{
	mavlink_message_t msg;	
    uint8_t buf[BUFFER_LENGTH];
	mavlink_test_common(1,1,&msg);
    float position[6] = {};

    /*Send Heartbeat */
	mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_HELICOPTER, MAV_AUTOPILOT_GENERIC, MAV_MODE_GUIDED_ARMED, 0, MAV_STATE_ACTIVE);
	int len = mavlink_msg_to_send_buffer(buf, &msg);
	printf("heart len=%d\n",len);
	for (int k = 0;k < len;k++) {
		printf("%x ",buf[k]);
	}
		
	/* Send Status */
	mavlink_msg_sys_status_pack(1, 200, &msg, 0, 0, 0, 500, 11000, -1, -1, 0, 0, 0, 0, 0, 0);
	len = mavlink_msg_to_send_buffer(buf, &msg);
	printf("\nstatus len=%d\n",len);
	for (int k = 0;k < len;k++) {
		printf("%x ",buf[k]);
	}
		
	/* Send Local Position */
	//mavlink_msg_local_position_ned_pack(1, 200, &msg, microsSinceEpoch(), 
	mavlink_msg_local_position_ned_pack(1, 200, &msg, 0xEB90, 
									position[0], position[1], position[2],
									position[3], position[4], position[5]);
	len = mavlink_msg_to_send_buffer(buf, &msg);
	printf("\nlocal position len=%d\n",len);
	for (int k = 0;k < len;k++) {
		printf("%x ",buf[k]);
	}
		
	/* Send attitude */
	//mavlink_msg_attitude_pack(1, 200, &msg, microsSinceEpoch(), 1.2, 1.7, 3.14, 0.01, 0.02, 0.03);
	mavlink_msg_attitude_pack(1, 200, &msg, 0xEB90, 1.2, 1.7, 3.14, 0.01, 0.02, 0.03);
	len = mavlink_msg_to_send_buffer(buf, &msg);
	printf("\nattitude len=%d\n",len);
	for (int k = 0;k < len;k++) {
		printf("%x ",buf[k]);
	}
	printf("\n");
    return 0;
}