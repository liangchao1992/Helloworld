deps_config := \
	src/kern-ucore/dde36/Kconfig \
	src/kern-ucore/module/Kconfig \
	src/kern-ucore/fs/Kconfig \
	src/kern-ucore/schedule/Kconfig \
	src/kern-ucore/mm/Kconfig \
	src/kern-ucore/numa/Kconfig \
	src/kern-ucore/Kconfig \
	/home/wuzw/ucore_empty/src/kern-ucore/arch/empty/Kconfig

include/config/auto.conf: \
	$(deps_config)

$(deps_config): ;
