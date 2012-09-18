#include<c++/begin_include.h>
#include <linux/netdevice.h>
#include<c++/end_include.h>

class Network_Driver
{
	public:
		static inline void *mool_netdev_priv(struct net_device *dev)
		{
			netdev_priv(dev);
		}

		static inline void mool_netif_start_queue(struct net_device *dev)
		{
			netif_start_queue(dev);
		}
		
		static inline void mool_netif_wake_queue(struct net_device *dev)
		{
			 netif_wake_queue(dev);
		}
		
};
