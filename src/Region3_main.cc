#include <iostream>
#include <cstdio>

#include "RegisterMap.hh"
#include "ProbeMap.hh"
#include "DelayValue.hh"
#include "PreScaleValue.hh"
#include "network.hh"
#include "UDPRBCP.hh"
#include "CommandMan.hh"
#include "FPGAModule.hh"
#include "CoinModule.hh"
#include "rbcp.h"
#include "errno.h"
#include "daq_funcs.hh"

using namespace HUL_Trigger;
using namespace Probe;
using namespace DelayValue;
int main(int argc, char* argv[])
{
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "hul_main [IP address]" << std::endl;
    return 0;
  }// usage
  
// body ------------------------------------------------------
  char* board_ip = argv[1];
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;


////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////

  //-------------------------------------------------------------------------
  // RGN3 : Region3 ( Else Or )Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam    ,               0);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam_TOF,               1);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam_Pi ,               2);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam_P  ,               3);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Coin1   ,               4);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Coin2   ,               5);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_For_E03 ,         499999 );
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Delay_PS_OR      ,               1);
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Delay_Else_OR    ,               1);
  fModule.WriteModule(   RGN3::mid,  RGN3::Width_Else_OR    ,               1);
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Delay_K_Scat     ,               6);
  fModule.WriteModule(   RGN3::mid,  RGN3::Width_K_Scat     ,               5);
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Selector_PS      ,       0b0100000);



////////////////////////////////////////////////////////////////////////////////////////////////
//           Read                                                                             // 
//         Read                                                                               // 
//       Read                                                                                 // 
////////////////////////////////////////////////////////////////////////////////////////////////

//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_P ,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_P ,    1);
//                                                       
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1);
//
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_P ,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_P ,    1) << std::endl;
//                                                                     
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1) << std::endl;

  return 0;

}// main