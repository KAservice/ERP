#ifndef UFormaDocRegGoodsCFH                  
#define UFormaDocRegGoodsCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegGoodsCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegGoodsCF();                                                           
   ~TFormaDocRegGoodsCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
