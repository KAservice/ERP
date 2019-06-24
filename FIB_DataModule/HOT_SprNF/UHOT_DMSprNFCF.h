#ifndef UHOT_DMSprNFCFH                  
#define UHOT_DMSprNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMSprNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMSprNFCF();                                                           
   ~THOT_DMSprNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
