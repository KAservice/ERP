#ifndef UDMRegGoodsCFH                  
#define UDMRegGoodsCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMRegGoodsCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMRegGoodsCF();                                                           
   ~TDMRegGoodsCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
