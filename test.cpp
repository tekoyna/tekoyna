void CUser::SendMyInfo()
{
	C3DMap* pMap = NULL;
	CKnights* pKnights = NULL;
	pMap = (C3DMap*)m_pMain->m_ZoneArray[m_iZoneIndex];
	if( !pMap ) return;

	int  send_index = 0, i=0, iLength = 0;
	char send_buff[2048];
	memset( send_buff, NULL, 2048);

	int x = 0; 
	int z = 0;

	
	//0E+AA01+07+4D724A756D626F+EA1F+B810+2800+02+0D+D000+00+
	if (strlen(m_pUserData->m_id) == 0)
		Close();

	SetByte( send_buff, WIZ_MYINFO, send_index );
	SetShort( send_buff, m_Sid, send_index );
	SetByte( send_buff, strlen(m_pUserData->m_id), send_index );
	SetString( send_buff, m_pUserData->m_id, strlen(m_pUserData->m_id), send_index );

	SetShort( send_buff, (WORD)m_pUserData->m_curx*10, send_index );
	SetShort( send_buff, (WORD)m_pUserData->m_curz*10, send_index );
	SetShort( send_buff, (short)m_pUserData->m_cury*10, send_index );

	SetByte( send_buff, m_pUserData->m_bNation, send_index );
	SetByte( send_buff, m_pUserData->m_bRace, send_index );
	SetShort( send_buff, m_pUserData->m_sClass, send_index );

	SetByte( send_buff, m_pUserData->m_bFace, send_index );
	
	//00+
	SetByte( send_buff, m_pUserData->m_hairr, send_index );
	SetByte( send_buff, m_pUserData->m_hairg, send_index );
	SetByte( send_buff, m_pUserData->m_hairb, send_index );
	SetByte( send_buff, m_pUserData->m_hairtype, send_index );


	SetByte( send_buff, m_pUserData->m_bRank, send_index );
	SetByte( send_buff, m_pUserData->m_bTitle, send_index );

	SetByte( send_buff, m_pUserData->m_bLevel, send_index );
	SetShort( send_buff, m_pUserData->m_bPoints, send_index );

	
	
	SetInt64( send_buff, m_iMaxExp, send_index );
	SetInt64( send_buff, m_pUserData->m_iExp, send_index );
	



	SetDWORD( send_buff, m_pUserData->m_iLoyalty, send_index );
	SetDWORD( send_buff, m_pUserData->m_iLoyaltyMonthly, send_index );

//
	SetShort( send_buff,m_pUserData->m_bKnights , send_index );
	SetByte( send_buff, m_pUserData->m_bFame, send_index );

	SetByte(send_buff, 0, send_index );

	if( m_pUserData->m_bKnights == 0 )	{
		SetByte( send_buff, 0x00, send_index );
		SetByte( send_buff, 0x00, send_index );

		SetByte( send_buff, 0x00, send_index );
		SetByte( send_buff, 0x00, send_index );

		SetByte( send_buff, 0x00, send_index );
		SetByte( send_buff, 0x00, send_index );
		SetByte( send_buff, 0x00, send_index );

		SetByte( send_buff, -1, send_index );
		SetByte( send_buff, -1, send_index );

		SetByte( send_buff, 0x00, send_index );
		SetByte( send_buff, 0x00, send_index );
		SetByte( send_buff, 0x00, send_index );

	}
	else {
		pKnights = m_pMain->m_KnightsArray.GetData( m_pUserData->m_bKnights );
		if( pKnights )	{
			iLength = strlen( pKnights->m_strName );
			SetByte( send_buff, 0, send_index ); // Knights ranking
			//pKnights->m_byRanking
			SetByte( send_buff, 12, send_index ); // 1 Normal Clan // 2 Trainin Clan // 3 -7 Acreditation // Royal 8-12
			SetByte( send_buff, iLength, send_index );
			SetString( send_buff, pKnights->m_strName, iLength, send_index );
			
			SetByte( send_buff, pKnights->m_byGrade, send_index ); // Knights grade
			SetByte( send_buff, pKnights->m_byRanking, send_index );
			SetByte( send_buff, pKnights->symbolversion, send_index );
			SetByte( send_buff, 0x00, send_index );

			SetByte( send_buff, pKnights->m_cloak_c , send_index ); // Knights cloak_c (sCape)
			SetByte( send_buff, pKnights->m_cloak_m, send_index ); // Knights cloak_m

			SetByte( send_buff, pKnights->m_cloak_r, send_index ); // R
			SetByte( send_buff, pKnights->m_cloak_g, send_index ); // G
			SetByte( send_buff, pKnights->m_cloak_b, send_index ); // B
				}
		else	{
			SetByte( send_buff, 0x00, send_index );
			SetByte( send_buff, 0x00, send_index );

			SetByte( send_buff, 0x00, send_index );
			SetByte( send_buff, 0x00, send_index );

			SetByte( send_buff, 0x00, send_index );
			SetByte( send_buff, 0x00, send_index );
			SetByte( send_buff, 0x00, send_index );

			SetByte( send_buff, -1, send_index );
			SetByte( send_buff, -1, send_index );

			SetByte( send_buff, 0x00, send_index );
			SetByte( send_buff, 0x00, send_index );
			SetByte( send_buff, 0x00, send_index );

		}
	}
	SetByte( send_buff, 0x00, send_index );
	SetByte( send_buff, 0x02, send_index );
	SetByte( send_buff, 0x03, send_index );
	SetByte( send_buff, 0x04, send_index );
	SetByte( send_buff, 0x05, send_index );


	SetShort( send_buff, m_iMaxHp, send_index );
	SetShort( send_buff, m_pUserData->m_sHp, send_index );

	SetShort( send_buff, m_iMaxMp, send_index );
	SetShort( send_buff, m_pUserData->m_sMp, send_index );

	SetDWORD( send_buff, m_sMaxWeight, send_index );
	SetDWORD( send_buff, m_sItemWeight, send_index );
	
	SetByte( send_buff, m_pUserData->m_bStr, send_index );
	SetByte( send_buff, m_sItemStr, send_index );
	SetByte( send_buff, m_pUserData->m_bSta, send_index );
	SetByte( send_buff, m_sItemSta, send_index );
	SetByte( send_buff, m_pUserData->m_bDex, send_index );
	SetByte( send_buff, m_sItemDex, send_index );
	SetByte( send_buff, m_pUserData->m_bIntel, send_index );
	SetByte( send_buff, m_sItemIntel, send_index );
	SetByte( send_buff, m_pUserData->m_bCha, send_index );
	SetByte( send_buff, m_sItemCham, send_index );	
	SetShort( send_buff, m_sTotalHit, send_index );
	SetShort( send_buff, m_sTotalAc, send_index );
//	SetShort( send_buff, m_sBodyAc+m_sItemAc, send_index );		<- ´©°¡ ÀÌ·¸°Ô ÇØºÃ¾î? --;	
	SetByte( send_buff, m_bFireR, send_index );
	SetByte( send_buff, m_bColdR, send_index );
	SetByte( send_buff, m_bLightningR, send_index );
	SetByte( send_buff, m_bMagicR, send_index );
	SetByte( send_buff, m_bDiseaseR, send_index );
	SetByte( send_buff, m_bPoisonR, send_index );
	SetDWORD( send_buff, m_pUserData->m_iGold, send_index );
// ÀÌ°Å ³ªÁß¿¡ ²À ÁÖ¼®ÇØ --;
	SetByte( send_buff, m_pUserData->m_bAuthority, send_index );
//01+0F+FF+000000000000502A1476F47E12010001000000000000000000000000124C420F193D0100000000000000000000000076F47E120100010000000000000000000000006E8B17130100010000000000000000000000004244420F193D010000000000000000000000000000000000000000000000000000000000000034F2A0061D1A010000000000000000000000003B4C4D1401000100000000000000000000000034F2A0061D1A0100000000000000000000000071B1AD130100010000000000000000000000002A48420F193D0100000000000000000000000071B1AD13010001000000000000000000000000FA4F420F193D01000000000000000000000000E253420F193D01000000000000000000000000B4BF090AAB23010000000000000000000000003C625D0E182E0100000000000000000000000024665D0E182E010000000000000000000000000C6A5D0E182E01000000000000000000000000F46D5D0E182E01000000000000000000000000DC715D0E182E01000000000000000000000000000000


	SetByte( send_buff, -1, send_index );
	SetByte( send_buff, -1, send_index );

//00+00+00+00+00+50+02+2D+0F+
	//77F47E12010001000000000000000000000000
    //9DA84E1E+201C+0100+00+0000+0000+0000+1BE7504F



	for(i=0; i<9; i++)
		SetByte(send_buff, m_pUserData->m_bstrSkill[i], send_index);

	for(i=0; i<SLOT_MAX+HAVE_MAX+EXTRA_MAX; i++ ) {
		//CheckExpirationTime(1,i)
		//when started :: CheckExpirationTime(2,i) -> For warehouse.
		SetDWORD( send_buff, m_pUserData->m_sItemArray[i].nNum, send_index );	
		SetShort( send_buff, m_pUserData->m_sItemArray[i].sDuration, send_index );
		SetShort( send_buff, m_pUserData->m_sItemArray[i].sCount, send_index );
		SetByte( send_buff, 0, send_index );
		SetShort( send_buff, 0, send_index ); //rental time (minutes
	 
		SetByte( send_buff, 0, send_index );
		SetByte( send_buff, 0, send_index );
		SetByte( send_buff, 0, send_index );
		SetByte( send_buff, 0, send_index );
//		
		SetDWORD( send_buff, day_diff(01,01,1970,31,12,2013) , send_index );

	}



	Send( send_buff, send_index );

	// AI ServerÂÊÀ¸·Î Á¤º¸ Àü¼Û..
	int  ai_send_index = 0;
	char ai_send_buff[256];
	memset( ai_send_buff, NULL, 256);

	SetByte( ai_send_buff, AG_USER_INFO, ai_send_index );
	SetShort( ai_send_buff, m_Sid, ai_send_index );
	SetShort( ai_send_buff, strlen(m_pUserData->m_id), ai_send_index );
	SetString( ai_send_buff, m_pUserData->m_id, strlen(m_pUserData->m_id), ai_send_index );
	SetByte( ai_send_buff, m_pUserData->m_bZone, ai_send_index );
	SetShort( ai_send_buff, m_iZoneIndex, ai_send_index );
	SetByte( ai_send_buff, m_pUserData->m_bNation, ai_send_index );
	SetByte( ai_send_buff, m_pUserData->m_bLevel, ai_send_index );
	SetShort( ai_send_buff, m_pUserData->m_sHp, ai_send_index );
	SetShort( ai_send_buff, m_pUserData->m_sMp, ai_send_index );
	SetShort( ai_send_buff, m_sTotalHit * m_bAttackAmount / 100, ai_send_index );  // Ç¥½Ã
	SetShort( ai_send_buff, m_sTotalAc + m_sACAmount, ai_send_index );  // Ç¥½Ã
	Setfloat( ai_send_buff, m_sTotalHitrate, ai_send_index );
	Setfloat( ai_send_buff, m_sTotalEvasionrate, ai_send_index );

// Yookozuna
	SetShort( ai_send_buff, m_sItemAc, ai_send_index);
	SetByte( ai_send_buff, m_bMagicTypeLeftHand, ai_send_index);
	SetByte( ai_send_buff, m_bMagicTypeRightHand, ai_send_index);
	SetShort( ai_send_buff, m_sMagicAmountLeftHand, ai_send_index);
	SetShort( ai_send_buff, m_sMagicAmountRightHand, ai_send_index);
	SetByte( ai_send_buff, m_pUserData->m_bAuthority, ai_send_index );
//
	m_pMain->Send_AIServer( m_pUserData->m_bZone, ai_send_buff, ai_send_index);

//	if( m_pUserData->m_bKnights > 0 )	{
//		m_pMain->m_KnightsManager.ModifyKnightsUser( m_pUserData->m_bKnights, m_pUserData->m_id, m_pUserData->m_bFame, m_pUserData->m_bLevel, m_pUserData->m_sClass, 1);
//	}
}
