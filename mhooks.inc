/*
	samp-hooks
<<<<<<< HEAD
	Copyright (C) 2014, mrdrifter

=======
	Copyright (C) 2015, mrdrifter
	
>>>>>>> origin/master
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	( at your option) any later version.

	This program is distributed in the hope that it will be useful, 
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if !defined SAMP_HOOKS
#define SAMP_HOOKS

enum hooks_data
{
	H_NULL, 
	H_INT, 
	H_FLOAT, 
	H_BOOL, 
	H_STRING
};

native HOOKS_CallHook(const callback[], {Float, _}:...);
//native HOOKS_CallLocalFunction(const callback[], {Float, _}:...); // CallLocalFunctionEx("OnPlayerConnect", H_INT, playerid); NOT TO USE! (function for testing)

#define HOOK:%0.%1(%2) forward %0H%1(%2); public %0H%1(%2)
#define @HOOKS_CallHook(%0) HOOKS_CallHook(%0)
//-------

public OnGameModeInit() return @HOOKS_CallHook("OnGameModeInit");
#if defined _ALS_OnGameModeInit

#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit @@HOnGameModeInit
forward @@HOnGameModeInit();

public OnGameModeExit() return @HOOKS_CallHook("OnGameModeExit");
#if defined _ALS_OnGameModeExit

#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit @@HOnGameModeExit
forward @@HOnGameModeExit();

public OnFilterScriptInit() return @HOOKS_CallHook("OnFilterScriptInit");
#if defined _ALS_OnFilterScriptInit

#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit @@HOnFilterScriptInit
forward @@HOnFilterScriptInit();

public OnFilterScriptExit() return @HOOKS_CallHook("OnFilterScriptExit");
#if defined _ALS_OnFilterScriptExit

#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit @@HOnFilterScriptExit
forward @@HOnFilterScriptExit();

public OnPlayerConnect(playerid) return @HOOKS_CallHook("OnPlayerConnect" , H_INT, playerid);
#if defined _ALS_OnPlayerConnect

#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect @@HOnPlayerConnect
forward @@HOnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason) return @HOOKS_CallHook("OnPlayerDisconnect" , H_INT, playerid, H_INT, reason);
#if defined _ALS_OnPlayerDisconnect

#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect @@HOnPlayerDisconnect
forward @@HOnPlayerDisconnect(playerid, reason);

public OnPlayerSpawn(playerid) return @HOOKS_CallHook("OnPlayerSpawn" , H_INT, playerid);
#if defined _ALS_OnPlayerSpawn

#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn @@HOnPlayerSpawn
forward @@HOnPlayerSpawn(playerid);

public OnPlayerDeath(playerid, killerid, reason) return @HOOKS_CallHook("OnPlayerDeath" , H_INT, playerid, H_INT, killerid, H_INT, reason);
#if defined _ALS_OnPlayerDeath

#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath @@HOnPlayerDeath
forward @@HOnPlayerDeath(playerid, killerid, reason);

public OnVehicleSpawn(vehicleid) return @HOOKS_CallHook("OnVehicleSpawn" , H_INT, vehicleid);
#if defined _ALS_OnVehicleSpawn

#undef OnVehicleSpawn
#else
	#define _ALS_OnVehicleSpawn
#endif
#define OnVehicleSpawn @@HOnVehicleSpawn
forward @@HOnVehicleSpawn(vehicleid);

public OnVehicleDeath(vehicleid, killerid) return @HOOKS_CallHook("OnVehicleDeath" , H_INT, vehicleid, H_INT, killerid);
#if defined _ALS_OnVehicleDeath

#undef OnVehicleDeath
#else
	#define _ALS_OnVehicleDeath
#endif
#define OnVehicleDeath @@HOnVehicleDeath
forward @@HOnVehicleDeath(vehicleid, killerid);

public OnPlayerText(playerid, text[]) return @HOOKS_CallHook("OnPlayerText" , H_INT, playerid, H_STRING, text);
#if defined _ALS_OnPlayerText

#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif
#define OnPlayerText @@HOnPlayerText
forward @@HOnPlayerText(playerid, text[]);

public OnPlayerCommandText(playerid, cmdtext[]) return @HOOKS_CallHook("OnPlayerCommandText" , H_INT, playerid, H_STRING, cmdtext);
#if defined _ALS_OnPlayerCommandText

#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText @@HOnPlayerCommandText
forward @@HOnPlayerCommandText(playerid, cmdtext[]);

public OnPlayerRequestClass(playerid, classid) return @HOOKS_CallHook("OnPlayerRequestClass" , H_INT, playerid, H_INT, classid);
#if defined _ALS_OnPlayerRequestClass

#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass @@HOnPlayerRequestClass
forward @@HOnPlayerRequestClass(playerid, classid);

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger) return @HOOKS_CallHook("OnPlayerEnterVehicle" , H_INT, playerid, H_INT, vehicleid, H_INT, ispassenger);
#if defined _ALS_OnPlayerEnterVehicle

#undef OnPlayerEnterVehicle
#else
	#define _ALS_OnPlayerEnterVehicle
#endif
#define OnPlayerEnterVehicle @@HOnPlayerEnterVehicle
forward @@HOnPlayerEnterVehicle(playerid, vehicleid, ispassenger);

public OnPlayerExitVehicle(playerid, vehicleid) return @HOOKS_CallHook("OnPlayerExitVehicle" , H_INT, playerid, H_INT, vehicleid);
#if defined _ALS_OnPlayerExitVehicle

#undef OnPlayerExitVehicle
#else
	#define _ALS_OnPlayerExitVehicle
#endif
#define OnPlayerExitVehicle @@HOnPlayerExitVehicle
forward @@HOnPlayerExitVehicle(playerid, vehicleid);

public OnPlayerStateChange(playerid, newstate, oldstate) return @HOOKS_CallHook("OnPlayerStateChange" , H_INT, playerid, H_INT, newstate, H_INT, oldstate);
#if defined _ALS_OnPlayerStateChange

#undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange @@HOnPlayerStateChange
forward @@HOnPlayerStateChange(playerid, newstate, oldstate);

public OnPlayerEnterCheckpoint(playerid) return @HOOKS_CallHook("OnPlayerEnterCheckpoint" , H_INT, playerid);
#if defined _ALS_OnPlayerEnterCheckpoint

#undef OnPlayerEnterCheckpoint
#else
	#define _ALS_OnPlayerEnterCheckpoint
#endif
#define OnPlayerEnterCheckpoint @@HOnPlayerEnterCheckpoint
forward @@HOnPlayerEnterCheckpoint(playerid);

public OnPlayerLeaveCheckpoint(playerid) return @HOOKS_CallHook("OnPlayerLeaveCheckpoint" , H_INT, playerid);
#if defined _ALS_OnPlayerLeaveCheckpoint

#undef OnPlayerLeaveCheckpoint
#else
	#define _ALS_OnPlayerLeaveCheckpoint
#endif
#define OnPlayerLeaveCheckpoint @@HOnPlayerLeaveCheckpoint
forward @@HOnPlayerLeaveCheckpoint(playerid);

/*
public OnPlayerEnterRaceCheckpoint(playerid) return @HOOKS_CallHook("OnPlayerEnterRaceCheckpoint" , H_INT, playerid);
#if defined _ALS_OnPlayerEnterRaceCheckpoint

#undef OnPlayerEnterRaceCheckpoint
#else
	#define _ALS_OnPlayerEnterRaceCheckpoint
#endif
#define OnPlayerEnterRaceCheckpoint @@HOnPlayerEnterRaceCheckpoint
forward @@HOnPlayerEnterRaceCheckpoint(playerid);


public OnPlayerLeaveRaceCheckpoint(playerid) return @HOOKS_CallHook("OnPlayerLeaveRaceCheckpoint" , H_INT, playerid);
#if defined _ALS_OnPlayerLeaveRaceCheckpoint

#undef OnPlayerLeaveRaceCheckpoint
#else
	#define _ALS_OnPlayerLeaveRaceCheckpoint
#endif
#define OnPlayerLeaveRaceCheckpoint @@HOnPlayerLeaveRaceCheckpoint
forward @@HOnPlayerLeaveRaceCheckpoint(playerid);
*/

public OnRconCommand(cmd[]) return @HOOKS_CallHook("OnRconCommand" , H_STRING, cmd);
#if defined _ALS_OnRconCommand

#undef OnRconCommand
#else
	#define _ALS_OnRconCommand
#endif
#define OnRconCommand @@HOnRconCommand
forward @@HOnRconCommand(cmd[]);

public OnPlayerRequestSpawn(playerid) return @HOOKS_CallHook("OnPlayerRequestSpawn" , H_INT, playerid);
#if defined _ALS_OnPlayerRequestSpawn

#undef OnPlayerRequestSpawn
#else
	#define _ALS_OnPlayerRequestSpawn
#endif
#define OnPlayerRequestSpawn @@HOnPlayerRequestSpawn
forward @@HOnPlayerRequestSpawn(playerid);

public OnObjectMoved(objectid) return @HOOKS_CallHook("OnObjectMoved" , H_INT, objectid);
#if defined _ALS_OnObjectMoved

#undef OnObjectMoved
#else
	#define _ALS_OnObjectMoved
#endif
#define OnObjectMoved @@HOnObjectMoved
forward @@HOnObjectMoved(objectid);

public OnPlayerObjectMoved(playerid, objectid) return @HOOKS_CallHook("OnPlayerObjectMoved" , H_INT, playerid, H_INT, objectid);
#if defined _ALS_OnPlayerObjectMoved

#undef OnPlayerObjectMoved
#else
	#define _ALS_OnPlayerObjectMoved
#endif
#define OnPlayerObjectMoved @@HOnPlayerObjectMoved
forward @@HOnPlayerObjectMoved(playerid, objectid);

public OnPlayerPickUpPickup(playerid, pickupid) return @HOOKS_CallHook("OnPlayerPickUpPickup" , H_INT, playerid, H_INT, pickupid);
#if defined _ALS_OnPlayerPickUpPickup

#undef OnPlayerPickUpPickup
#else
	#define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup @@HOnPlayerPickUpPickup
forward @@HOnPlayerPickUpPickup(playerid, pickupid);

public OnVehicleMod(playerid, vehicleid, componentid) return @HOOKS_CallHook("OnVehicleMod" , H_INT, playerid, H_INT, vehicleid, H_INT, componentid);
#if defined _ALS_OnVehicleMod

#undef OnVehicleMod
#else
	#define _ALS_OnVehicleMod
#endif
#define OnVehicleMod @@HOnVehicleMod
forward @@HOnVehicleMod(playerid, vehicleid, componentid);

public OnEnterExitModShop(playerid, enterexit, interiorid) return @HOOKS_CallHook("OnEnterExitModShop" , H_INT, playerid, H_INT, enterexit, H_INT, interiorid);
#if defined _ALS_OnEnterExitModShop

#undef OnEnterExitModShop
#else
	#define _ALS_OnEnterExitModShop
#endif
#define OnEnterExitModShop @@HOnEnterExitModShop
forward @@HOnEnterExitModShop(playerid, enterexit, interiorid);

public OnVehiclePaintjob(playerid, vehicleid, paintjobid) return @HOOKS_CallHook("OnVehiclePaintjob" , H_INT, playerid, H_INT, vehicleid, H_INT, paintjobid);
#if defined _ALS_OnVehiclePaintjob

#undef OnVehiclePaintjob
#else
	#define _ALS_OnVehiclePaintjob
#endif
#define OnVehiclePaintjob @@HOnVehiclePaintjob
forward @@HOnVehiclePaintjob(playerid, vehicleid, paintjobid);

public OnVehicleRespray(playerid, vehicleid, color1, color2) return @HOOKS_CallHook("OnVehicleRespray" , H_INT, playerid, H_INT, vehicleid, H_INT, color1, H_INT, color2);
#if defined _ALS_OnVehicleRespray

#undef OnVehicleRespray
#else
	#define _ALS_OnVehicleRespray
#endif
#define OnVehicleRespray @@HOnVehicleRespray
forward @@HOnVehicleRespray(playerid, vehicleid, color1, color2);

/*
public OnVehicleDamageStatusUpdate(vehicleid, playerid) return @HOOKS_CallHook("OnVehicleDamageStatusUpdate" , H_INT, vehicleid, H_INT, playerid);
#if defined _ALS_OnVehicleDamageStatusUpdate

#undef OnVehicleDamageStatusUpdate
#else
	#define _ALS_OnVehicleDamageStatusUpdate
#endif
#define OnVehicleDamageStatusUpdate @@HOnVehicleDamageStatusUpdate
forward @@HOnVehicleDamageStatusUpdate(vehicleid, playerid);
*/

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z) return @HOOKS_CallHook("OnUnoccupiedVehicleUpdate" , H_INT, vehicleid, H_INT, playerid, H_INT, passenger_seat, H_FLOAT, new_x, H_FLOAT, new_y, H_FLOAT, new_z, H_FLOAT, vel_x, H_FLOAT, vel_y, H_FLOAT, vel_z);
#if defined _ALS_OnUnoccupiedVehicleUpdate

#undef OnUnoccupiedVehicleUpdate
#else
	#define _ALS_OnUnoccupiedVehicleUpdate
#endif
#define OnUnoccupiedVehicleUpdate @@HOnUnoccupiedVehicleUpdate
forward @@HOnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);

public OnPlayerSelectedMenuRow(playerid, row) return @HOOKS_CallHook("OnPlayerSelectedMenuRow" , H_INT, playerid, H_INT, row);
#if defined _ALS_OnPlayerSelectedMenuRow

#undef OnPlayerSelectedMenuRow
#else
	#define _ALS_OnPlayerSelectedMenuRow
#endif
#define OnPlayerSelectedMenuRow @@HOnPlayerSelectedMenuRow
forward @@HOnPlayerSelectedMenuRow(playerid, row);

public OnPlayerExitedMenu(playerid) return @HOOKS_CallHook("OnPlayerExitedMenu" , H_INT, playerid);
#if defined _ALS_OnPlayerExitedMenu

#undef OnPlayerExitedMenu
#else
	#define _ALS_OnPlayerExitedMenu
#endif
#define OnPlayerExitedMenu @@HOnPlayerExitedMenu
forward @@HOnPlayerExitedMenu(playerid);

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid) return @HOOKS_CallHook("OnPlayerInteriorChange" , H_INT, playerid, H_INT, newinteriorid, H_INT, oldinteriorid);
#if defined _ALS_OnPlayerInteriorChange

#undef OnPlayerInteriorChange
#else
	#define _ALS_OnPlayerInteriorChange
#endif
#define OnPlayerInteriorChange @@HOnPlayerInteriorChange
forward @@HOnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) return @HOOKS_CallHook("OnPlayerKeyStateChange" , H_INT, playerid, H_INT, newkeys, H_INT, oldkeys);
#if defined _ALS_OnPlayerKeyStateChange

#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange @@HOnPlayerKeyStateChange
forward @@HOnPlayerKeyStateChange(playerid, newkeys, oldkeys);

public OnRconLoginAttempt( ip[], password[], success) return @HOOKS_CallHook("OnRconLoginAttempt" , H_STRING, ip, H_STRING, password, H_INT, success);
#if defined _ALS_OnRconLoginAttempt

#undef OnRconLoginAttempt
#else
	#define _ALS_OnRconLoginAttempt
#endif
#define OnRconLoginAttempt @@HOnRconLoginAttempt
forward @@HOnRconLoginAttempt( ip[], password[], success);

/*
public OnPlayerUpdate(playerid) return @HOOKS_CallHook("OnPlayerUpdate" , H_INT, playerid);
#if defined _ALS_OnPlayerUpdate

#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate @@HOnPlayerUpdate
forward @@HOnPlayerUpdate(playerid);
*/

public OnPlayerStreamIn(playerid, forplayerid) return @HOOKS_CallHook("OnPlayerStreamIn" , H_INT, playerid, H_INT, forplayerid);
#if defined _ALS_OnPlayerStreamIn

#undef OnPlayerStreamIn
#else
	#define _ALS_OnPlayerStreamIn
#endif
#define OnPlayerStreamIn @@HOnPlayerStreamIn
forward @@HOnPlayerStreamIn(playerid, forplayerid);

public OnPlayerStreamOut(playerid, forplayerid) return @HOOKS_CallHook("OnPlayerStreamOut" , H_INT, playerid, H_INT, forplayerid);
#if defined _ALS_OnPlayerStreamOut

#undef OnPlayerStreamOut
#else
	#define _ALS_OnPlayerStreamOut
#endif
#define OnPlayerStreamOut @@HOnPlayerStreamOut
forward @@HOnPlayerStreamOut(playerid, forplayerid);

public OnVehicleStreamIn(vehicleid, forplayerid) return @HOOKS_CallHook("OnVehicleStreamIn" , H_INT, vehicleid, H_INT, forplayerid);
#if defined _ALS_OnVehicleStreamIn

#undef OnVehicleStreamIn
#else
	#define _ALS_OnVehicleStreamIn
#endif
#define OnVehicleStreamIn @@HOnVehicleStreamIn
forward @@HOnVehicleStreamIn(vehicleid, forplayerid);

public OnVehicleStreamOut(vehicleid, forplayerid) return @HOOKS_CallHook("OnVehicleStreamOut" , H_INT, vehicleid, H_INT, forplayerid);
#if defined _ALS_OnVehicleStreamOut

#undef OnVehicleStreamOut
#else
	#define _ALS_OnVehicleStreamOut
#endif
#define OnVehicleStreamOut @@HOnVehicleStreamOut
forward @@HOnVehicleStreamOut(vehicleid, forplayerid);

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) return @HOOKS_CallHook("OnDialogResponse" , H_INT, playerid, H_INT, dialogid, H_INT, response, H_INT, listitem, H_STRING, inputtext);
#if defined _ALS_OnDialogResponse

#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif
#define OnDialogResponse @@HOnDialogResponse
forward @@HOnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart) return @HOOKS_CallHook("OnPlayerTakeDamage" , H_INT, playerid, H_INT, issuerid, H_FLOAT, amount, H_INT, weaponid, H_INT, bodypart);
#if defined _ALS_OnPlayerTakeDamage

#undef OnPlayerTakeDamage
#else
	#define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage @@HOnPlayerTakeDamage
forward @@HOnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) return @HOOKS_CallHook("OnPlayerGiveDamage" , H_INT, playerid, H_INT, damagedid, H_FLOAT, amount, H_INT, weaponid, H_INT, bodypart);
#if defined _ALS_OnPlayerGiveDamage

#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
#define OnPlayerGiveDamage @@HOnPlayerGiveDamage
forward @@HOnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ) return @HOOKS_CallHook("OnPlayerClickMap" , H_INT, playerid, H_FLOAT, fX, H_FLOAT, fY, H_FLOAT, fZ);
#if defined _ALS_OnPlayerClickMap

#undef OnPlayerClickMap
#else
	#define _ALS_OnPlayerClickMap
#endif
#define OnPlayerClickMap @@HOnPlayerClickMap
forward @@HOnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);

public OnPlayerClickTextDraw(playerid, Text:clickedid) return @HOOKS_CallHook("OnPlayerClickTextDraw" , H_INT, playerid, H_INT, _:clickedid);
#if defined _ALS_OnPlayerClickTextDraw

#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw @@HOnPlayerClickTextDraw
forward @@HOnPlayerClickTextDraw(playerid, Text:clickedid);
/*
public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid) return @HOOKS_CallHook("OnPlayerClickPlayerTextDraw" , H_INT, playerid, H_INT, playertextid);
#if defined _ALS_OnPlayerClickPlayerTextDraw

#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTextDraw
#endif
#define OnPlayerClickPlayerTextDraw @@HOnPlayerClickPlayerTextDraw
forward @@HOnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
*/

public OnIncomingConnection(playerid, ip_address[], port) return @HOOKS_CallHook("OnIncomingConnection" , H_INT, playerid, H_STRING, ip_address, H_INT, port);
#if defined _ALS_OnIncomingConnection

#undef OnIncomingConnection
#else
	#define _ALS_OnIncomingConnection
#endif
#define OnIncomingConnection @@HOnIncomingConnection
forward @@HOnIncomingConnection(playerid, ip_address[], port);
/*
public OnTrailerUpdate(playerid, vehicleid) return @HOOKS_CallHook("OnTrailerUpdate" , H_INT, playerid, H_INT, vehicleid);
#if defined _ALS_OnTrailerUpdate

#undef OnTrailerUpdate
#else
	#define _ALS_OnTrailerUpdate
#endif
#define OnTrailerUpdate @@HOnTrailerUpdate
forward @@HOnTrailerUpdate(playerid, vehicleid);
*/
public OnPlayerClickPlayer(playerid, clickedplayerid, source) return @HOOKS_CallHook("OnPlayerClickPlayer" , H_INT, playerid, H_INT, clickedplayerid, H_INT, source);
#if defined _ALS_OnPlayerClickPlayer

#undef OnPlayerClickPlayer
#else
	#define _ALS_OnPlayerClickPlayer
#endif
#define OnPlayerClickPlayer @@HOnPlayerClickPlayer
forward @@HOnPlayerClickPlayer(playerid, clickedplayerid, source);

public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ) return @HOOKS_CallHook("OnPlayerSelectObject" , H_INT, playerid, H_INT, type, H_INT, objectid, H_INT, modelid, H_FLOAT, fX, H_FLOAT, fY, H_FLOAT, fZ);
#if defined _ALS_OnPlayerSelectObject

#undef OnPlayerSelectObject
#else
	#define _ALS_OnPlayerSelectObject
#endif
#define OnPlayerSelectObject @@HOnPlayerSelectObject
forward @@HOnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ);

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) return @HOOKS_CallHook("OnPlayerWeaponShot" , H_INT, playerid, H_INT, weaponid, H_INT, hittype, H_INT, hitid, H_FLOAT, fX, H_FLOAT, fY, H_FLOAT, fZ);
#if defined _ALS_OnPlayerWeaponShot

#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
#define OnPlayerWeaponShot @@HOnPlayerWeaponShot
forward @@HOnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);

public @receivestring(const message[], const source[]) return @HOOKS_CallHook("@receivestring" , H_STRING, message, H_STRING, source);
#if defined _ALS_@receivestring

#undef @receivestring
#else
	#define _ALS_@receivestring
#endif
#define @receivestring @@H@receivestring
forward @@H@receivestring(const message[], const source[]);

public @receivepacket(const packet[], size, const source[]) return @HOOKS_CallHook("@receivepacket" , H_STRING, packet, H_INT, size, H_STRING, source);
#if defined _ALS_@receivepacket

#undef @receivepacket
#else
	#define _ALS_@receivepacket
#endif
#define @receivepacket @@H@receivepacket
forward @@H@receivepacket(const packet[], size, const source[]);

#endif
