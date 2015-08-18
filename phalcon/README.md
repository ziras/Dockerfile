Composer for PHPUnit for Phalcon 1.3.4
======================================

Usage
-----

Execute `` composer install `` inside a foliolin/phalcon:1.3.4 container.

The container will be deleted when `` composer install `` has finished.

Then transfer the ownership of the `` vendor `` directory to the current user.

	docker run --rm \
		--volume $PWD:/var/www/html foliolin/phalcon:1.3.4 \
		composer install && \
	sudo chown -R $USER:$USER vendor/
